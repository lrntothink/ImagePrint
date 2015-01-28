// EventSink.cpp : CEventSink 的实现

#include "stdafx.h"
#include "EventSink.h"


// CEventSink


STDMETHODIMP CEventSink::imagePrint(BSTR url)
{
	// TODO: 在此添加实现代码
	int argSilent = 1;
	_TCHAR* argUrl = url;
	_TCHAR* argOut = _T("d:/111.jpg");
	unsigned int argDelay = 0;
	unsigned int argMinWidth = 800;
	unsigned int argMaxWait = 90000;
	if (!AtlAxWinInit())
		return EXIT_FAILURE;
	CMain wnd(argUrl, argOut, argDelay, argSilent);


	RECT rcMain = { 0, 0, argMinWidth, 600 };
	//wnd.Create(NULL, rcMain, _T("IECapt"), WS_POPUP);

	wnd.Create( NULL, CWindow::rcDefault, _T("Hello"),WS_POPUP );
	wnd.SetTimer(1, 2000);
	MSG msg;
	while( GetMessage( &msg, NULL, 0, 0 ) ){
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	return S_OK;
}
