// dllmain.h : 模块类的声明。

class CImagePrintModule : public CAtlDllModuleT< CImagePrintModule >
{
public :
	DECLARE_LIBID(LIBID_ImagePrintLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_IMAGEPRINT, "{9E8D9683-28F3-4294-BECD-A1FD60939B11}")
};

extern class CImagePrintModule _AtlModule;
