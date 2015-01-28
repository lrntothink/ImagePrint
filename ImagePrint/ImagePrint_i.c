

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IEventSink,0x2A0D436B,0x2C48,0x445C,0x8F,0x1B,0xE5,0xB5,0x20,0x32,0x9A,0x0E);


MIDL_DEFINE_GUID(IID, LIBID_ImagePrintLib,0xAAAE4D18,0x90C8,0x4CCB,0x93,0x5F,0x78,0x78,0xBF,0x9A,0x3F,0x23);


MIDL_DEFINE_GUID(IID, DIID__IEventSinkEvents,0xD2D9DBB6,0xA34F,0x4C2D,0x96,0x3B,0x3A,0xC4,0x4B,0xD9,0xCF,0xD7);


MIDL_DEFINE_GUID(CLSID, CLSID_EventSink,0x86124585,0x90FD,0x4033,0x88,0x83,0x0B,0x24,0xB1,0xA4,0x6C,0xB6);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



