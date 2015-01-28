// EventSink.h : CEventSink 的声明

#pragma once
#include "resource.h"       // 主符号
#include "Main.h"
#include "ImagePrint_i.h"
#include "_IEventSinkEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// CEventSink

class ATL_NO_VTABLE CEventSink :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEventSink, &CLSID_EventSink>,
	public IConnectionPointContainerImpl<CEventSink>,
	public CProxy_IEventSinkEvents<CEventSink>,
	public IObjectWithSiteImpl<CEventSink>,
	public IDispatchImpl<IEventSink, &IID_IEventSink, &LIBID_ImagePrintLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CEventSink():m_pMain(NULL)
	{
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_EVENTSINK)


	BEGIN_COM_MAP(CEventSink)
		COM_INTERFACE_ENTRY(IEventSink)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
		COM_INTERFACE_ENTRY(IObjectWithSite)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CEventSink)
		CONNECTION_POINT_ENTRY(__uuidof(_IEventSinkEvents))
	END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	CMain *m_pMain;
	STDMETHOD(imagePrint)(BSTR url);
};

OBJECT_ENTRY_AUTO(__uuidof(EventSink), CEventSink)
