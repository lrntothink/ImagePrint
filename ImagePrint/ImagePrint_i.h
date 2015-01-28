

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Jan 27 18:48:34 2015
 */
/* Compiler settings for .\ImagePrint.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ImagePrint_i_h__
#define __ImagePrint_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IEventSink_FWD_DEFINED__
#define __IEventSink_FWD_DEFINED__
typedef interface IEventSink IEventSink;
#endif 	/* __IEventSink_FWD_DEFINED__ */


#ifndef ___IEventSinkEvents_FWD_DEFINED__
#define ___IEventSinkEvents_FWD_DEFINED__
typedef interface _IEventSinkEvents _IEventSinkEvents;
#endif 	/* ___IEventSinkEvents_FWD_DEFINED__ */


#ifndef __EventSink_FWD_DEFINED__
#define __EventSink_FWD_DEFINED__

#ifdef __cplusplus
typedef class EventSink EventSink;
#else
typedef struct EventSink EventSink;
#endif /* __cplusplus */

#endif 	/* __EventSink_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IEventSink_INTERFACE_DEFINED__
#define __IEventSink_INTERFACE_DEFINED__

/* interface IEventSink */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IEventSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A0D436B-2C48-445C-8F1B-E5B520329A0E")
    IEventSink : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE imagePrint( 
            /* [in] */ BSTR url) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEventSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEventSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEventSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEventSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEventSink * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEventSink * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEventSink * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEventSink * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *imagePrint )( 
            IEventSink * This,
            /* [in] */ BSTR url);
        
        END_INTERFACE
    } IEventSinkVtbl;

    interface IEventSink
    {
        CONST_VTBL struct IEventSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEventSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEventSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEventSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEventSink_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEventSink_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEventSink_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEventSink_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEventSink_imagePrint(This,url)	\
    ( (This)->lpVtbl -> imagePrint(This,url) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEventSink_INTERFACE_DEFINED__ */



#ifndef __ImagePrintLib_LIBRARY_DEFINED__
#define __ImagePrintLib_LIBRARY_DEFINED__

/* library ImagePrintLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ImagePrintLib;

#ifndef ___IEventSinkEvents_DISPINTERFACE_DEFINED__
#define ___IEventSinkEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IEventSinkEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IEventSinkEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D2D9DBB6-A34F-4C2D-963B-3AC44BD9CFD7")
    _IEventSinkEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IEventSinkEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IEventSinkEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IEventSinkEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IEventSinkEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IEventSinkEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IEventSinkEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IEventSinkEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IEventSinkEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IEventSinkEventsVtbl;

    interface _IEventSinkEvents
    {
        CONST_VTBL struct _IEventSinkEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IEventSinkEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IEventSinkEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IEventSinkEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IEventSinkEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IEventSinkEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IEventSinkEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IEventSinkEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IEventSinkEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_EventSink;

#ifdef __cplusplus

class DECLSPEC_UUID("86124585-90FD-4033-8883-0B24B1A46CB6")
EventSink;
#endif
#endif /* __ImagePrintLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


