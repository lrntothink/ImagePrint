#include "StdAfx.h"
#include "Main.h"
#include "EventSink.h"

CMain::CMain(void)
{
}

CMain::CMain(LPTSTR uri, LPTSTR file, UINT delay, BOOL silent) 
{
	m_URI=uri;
	m_fileName=file;
	m_bSilent=silent;
	m_uDelay=delay;
	m_dwCookie = 0;
}


CMain::~CMain(void)
{
}

LRESULT CMain::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	HRESULT hr;
	RECT old;
	IUnknown * pUnk = NULL;
	GetClientRect(&old);

	m_hwndWebBrowser = ::CreateWindow(_T(ATLAXWIN_CLASS), m_URI,
		/*WS_POPUP|*/WS_CHILD|WS_DISABLED, old.top, old.left, old.right,
		old.bottom, m_hWnd, NULL, ::GetModuleHandle(NULL), NULL);

	// TODO: Quit if m_hwndWebBrowser is null.

	hr = AtlAxGetControl(m_hwndWebBrowser, &m_pWebBrowserUnk);

	if (FAILED(hr))
		return 1;

	if (m_pWebBrowserUnk == NULL)
		return 1;

	hr = m_pWebBrowserUnk->QueryInterface(IID_IWebBrowser2, (void**)&m_pWebBrowser);

	if (FAILED(hr))
		return 1;

	// Set whether it should be silent
	m_pWebBrowser->put_Silent(m_bSilent ? VARIANT_TRUE : VARIANT_FALSE);

	hr = CComObject<CEventSink>::CreateInstance(&m_pEventSink);

	if (FAILED(hr))
		return 1;

	m_pEventSink->m_pMain = this;

	hr = AtlAdvise(m_pWebBrowserUnk, m_pEventSink->GetUnknown(),
		DIID_DWebBrowserEvents2, &m_dwCookie);

	if (FAILED(hr))
		return 1;
	return 0;
}

LRESULT CMain::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	HRESULT hr;

	if (m_dwCookie != 0)
		hr = AtlUnadvise(m_pWebBrowserUnk, DIID_DWebBrowserEvents2, m_dwCookie);

	m_pWebBrowser.Release();
	m_pWebBrowserUnk.Release();

	PostQuitMessage(0);
	return 0;
}

LRESULT CMain::OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_hwndWebBrowser != NULL)
		::MoveWindow(m_hwndWebBrowser, 0, 0, LOWORD(lParam), HIWORD(lParam), TRUE);

	return 0;
}

LRESULT CMain::OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	KillTimer(1);
	BOOL bSuccess = SaveSnapshot();
	PostMessage(WM_CLOSE);
	return 0;
}


BOOL CMain::SaveSnapshot(void)
{
	long bodyHeight, bodyWidth, rootHeight, rootWidth, height, width;

	CComPtr<IDispatch> pDispatch;

	// TODO: "If the document object type is not safe for scripting,
	// this method returns successfully but sets ppDisp to NULL. For
	// Internet Explorer 7 and later, the return code is S_FALSE..."

	HRESULT hr = m_pWebBrowser->get_Document(&pDispatch);

	if (FAILED(hr))
		return true;

	CComPtr<IHTMLDocument2> spDocument;
	hr = pDispatch->QueryInterface(IID_IHTMLDocument2, (void**)&spDocument);

	if (FAILED(hr))
		return true;

	CComPtr<IHTMLElement> spBody;
	hr = spDocument->get_body(&spBody);

	// Apparently with MSHTML failing to get the body is not a failure,
	// so if there is no HTML body to get, which may be the case with
	// SVG images loaded directly, this succeeds but sets spBody to the
	// NULL pointer, leading to a crash. I am not sure how to obtain
	// the sizing information for SVG documents so this errors out here.
	// A work around would be the make HTML host documents or wrapping
	// the SVG code in a XHTML document, but that may break scripts.
	if (FAILED(hr) || spBody == NULL)
		return true;

	CComPtr<IHTMLElement2> spBody2;
	hr = spBody->QueryInterface(IID_IHTMLElement2, (void**)&spBody2);

	if (FAILED(hr))
		return true;

	hr = spBody2->get_scrollHeight(&bodyHeight);

	if (FAILED(hr))
		return true;

	hr = spBody2->get_scrollWidth(&bodyWidth);

	if (FAILED(hr))
		return true;

	CComPtr<IHTMLDocument3> spDocument3;
	hr = pDispatch->QueryInterface(IID_IHTMLDocument3, (void**)&spDocument3);

	if (FAILED(hr))
		return true;

	// We also need to get the dimensions from the <html> due to quirks
	// and standards mode differences. Perhaps this should instead check
	// whether we are in quirks mode? How does it work with IE8?
	CComPtr<IHTMLElement> spHtml;
	hr = spDocument3->get_documentElement(&spHtml);

	if (FAILED(hr))
		return true;

	CComPtr<IHTMLElement2> spHtml2;
	hr = spHtml->QueryInterface(IID_IHTMLElement2, (void**)&spHtml2);

	if (FAILED(hr))
		return true;

	hr = spHtml2->get_scrollHeight(&rootHeight);

	if (FAILED(hr))
		return true;

	hr = spHtml2->get_scrollWidth(&rootWidth);

	if (FAILED(hr))
		return true;

	width = bodyWidth>rootWidth?bodyWidth:rootWidth;
	height = rootHeight > bodyHeight ? rootHeight : bodyHeight;

	// TODO: What if width or height exceeds 32767? It seems Windows limits
	// the window size, and Internet Explorer does not draw what's not visible.
	width = width +200;
	height = height +200;
	::MoveWindow(m_hwndWebBrowser, 0, 0, width, height, TRUE);

	CComPtr<IViewObject2> spViewObject;

	// This used to get the interface from the m_pWebBrowser but that seems
	// to be an undocumented feature, so we get it from the Document instead.
	hr = spDocument3->QueryInterface(IID_IViewObject2, (void**)&spViewObject);

	if (FAILED(hr))
		return true;

	RECTL rcBounds = { 0, 0, width+80, height+80 };
	CImage image;

	// TODO: check return value;
	// TODO: somehow enable alpha
	image.Create(width, height, 24);

	HDC imgDc = image.GetDC();
	hr = spViewObject->Draw(DVASPECT_CONTENT, -1, NULL, NULL, imgDc,
		imgDc, &rcBounds, NULL, NULL, 0);
	image.ReleaseDC();
	//if (SUCCEEDED(hr))
		//hr = image.Save(m_fileName);

	PRINTDLG pd;
	// Initialize PRINTDLG
	ZeroMemory(&pd, sizeof(pd));
	pd.lStructSize = sizeof(pd);
	pd.hwndOwner   = NULL;
	pd.hDevMode    = NULL;     // Don't forget to free or store hDevMode
	pd.hDevNames   = NULL;     // Don't forget to free or store hDevNames
	pd.Flags       = PD_RETURNDEFAULT | PD_RETURNDC; 
	pd.nCopies     = 1;
	pd.nFromPage   = 0xFFFF; 
	pd.nToPage     = 0xFFFF; 
	pd.nMinPage    = 1; 
	pd.nMaxPage    = 0xFFFF; 
	DOCINFO di={sizeof(DOCINFO),L"printer",NULL};
	if (PrintDlg(&pd)==TRUE) 
	{ 
		// pd.hDC就是你要的打印dc了.
		// 这里就是你要画打印的东西
		/*if(StartDoc(pd.hDC,&di)>0) 
		{
		StartPage(pd.hDC); 
		SaveDC(pd.hDC); 

		RECT rect={50,50,9900,14500};
		BSTR a = L"dddddddddddd";
		DrawText(pd.hDC,a,sizeof(a),&rect,DT_LEFT | DT_TOP | DT_WORDBREAK | DT_EDITCONTROL);

		//TextOut(hdcprint,1,1,"这是一个例子",12);
		RestoreDC(pd.hDC,-1); 
		EndPage(pd.hDC); 
		EndDoc(pd.hDC); 
		//MessageBox("打印完毕!","提示",MB_ICONINFORMATION);
		}
		*/

		long m_lPageWidth = GetDeviceCaps(pd.hDC, PHYSICALWIDTH);
		long m_lPageHeight = GetDeviceCaps(pd.hDC, PHYSICALHEIGHT);

		long imageWidth = image.GetWidth();
		long imageHeight = image.GetHeight();
		long m_fScale = m_lPageWidth /imageWidth;

		/*RECT rcDest;

		long m_fScale = m_lPageWidth /imageWidth;

		SetRect(&rcDest, 0, 0, m_lPageWidth, m_lPageHeight/2); 
		rcDest.left = (m_lPageWidth - imageWidth*m_fScale)/2;
		rcDest.right = rcDest.left + imageWidth*m_fScale;
		rcDest.top = 0;
		rcDest.bottom = rcDest.top + imageHeight*m_fScale;*/
		//开始执行一个打印作业
		DOCINFO di = {sizeof(DOCINFO), L"理财凭单打印", NULL};
		if(StartDoc(pd.hDC, &di) > 0) 
		{
			int i ;
			int page = m_fScale * imageHeight/m_lPageHeight+1;
			for(i=1;i<=page;i++)
			{
				StartPage(pd.hDC); //打印走纸，开始打印
				SaveDC(pd.hDC);  //保存打印机设备句柄
				long viewHeight = m_lPageHeight<m_fScale*imageHeight?m_lPageHeight:m_fScale*imageHeight;
				image.Draw(pd.hDC,0,0,m_lPageWidth,viewHeight,0,(i-1)*imageHeight/page,imageWidth,imageHeight/page);
				//image.BitBlt(pd.hDC,0,0,SRCCOPY);
				//image.BitBlt(pd.hDC,2000,2000,4000,4000,0,0,SRCCOPY);
				//image.StretchBlt(pd.hDC,20,20,800,600,SRCCOPY);

				RestoreDC(pd.hDC, -1);  // 回复打印机设备句柄
				EndPage(pd.hDC);  //打印纸停纸，停止打印

			}
			EndDoc(pd.hDC); //结束一个打印作业

			//MessageBox(NULL, "图片打印成功", "提示", MB_OK | MB_ICONINFORMATION);
		}
		// Delete DC
		DeleteDC(pd.hDC);
	}
	return false;
}

