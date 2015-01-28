// EventSink.h : CEventSink ������

#pragma once
#include "resource.h"       // ������
#include "Main.h"
#include "ImagePrint_i.h"
#include "_IEventSinkEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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
