#pragma once

class CMain : public CWindowImpl<CMain>
{
	friend class CEventSink;
public:
	CMain(void);
	CMain(LPTSTR uri, LPTSTR file, UINT delay, BOOL silent) ;
	~CMain(void);
	BEGIN_MSG_MAP(CMain)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		MESSAGE_HANDLER(WM_SIZE, OnSize)
		MESSAGE_HANDLER(WM_TIMER, OnTimer)
	END_MSG_MAP()
	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	BOOL SaveSnapshot(void);
private:
	LPTSTR m_URI;
	LPTSTR m_fileName;
	BOOL   m_bSilent;
	UINT   m_uDelay;
	UINT   m_nIDEvent;
protected:
	CComPtr<IUnknown> m_pWebBrowserUnk;
	CComPtr<IWebBrowser2> m_pWebBrowser;
	CComObject<CEventSink>* m_pEventSink;
	HWND m_hwndWebBrowser;
	DWORD m_dwCookie;
};
