#include <comdef.h>

void __stdcall _com_raise_error(HRESULT hr, IErrorInfo* perrinfo) throw(_com_error) {
  throw _com_error(hr, perrinfo);
}

void __stdcall _com_issue_error(HRESULT hr) throw(_com_error) {
    ICreateErrorInfo* erinf;
    IErrorInfo* errintf;
    if ( SUCCEEDED(CreateErrorInfo(&erinf))) {
        if ( SUCCEEDED(erinf->QueryInterface(IID_IErrorInfo, reinterpret_cast<void**>(&errintf)))) {
            SetErrorInfo(0,errintf);
            erinf->Release();
            _com_raise_error(hr,errintf);
        }
        erinf->Release();
    }
}

#pragma argsused
void __stdcall _com_issue_errorex(HRESULT hr, IUnknown* punknwn, REFIID riid) throw(_com_error) {
    IErrorInfo* errintf;
    if ( (punknwn != NULL) && SUCCEEDED(punknwn->QueryInterface(IID_IErrorInfo, reinterpret_cast<void**>(&errintf)))) {
         errintf->AddRef(); 
        _com_raise_error(hr,errintf);
    } else {
      ICreateErrorInfo* erinf;
      if ( SUCCEEDED(CreateErrorInfo(&erinf))) {
          erinf->SetGUID(riid);
          if ( SUCCEEDED(erinf->QueryInterface(IID_IErrorInfo, reinterpret_cast<void**>(&errintf)))) {
              SetErrorInfo(0,errintf);
              erinf->Release();
              _com_raise_error(hr,errintf);
          }
          erinf->Release();
      }
    }
}

/*
HRESULT __stdcall
        _com_dispatch_propget(IDispatch*, DISPID, VARTYPE, void*) throw(_com_error);
HRESULT __cdecl
        _com_dispatch_propput(IDispatch*, DISPID, VARTYPE, ...) throw(_com_error);
HRESULT __cdecl
        _com_dispatch_method(IDispatch*, DISPID, WORD, VARTYPE, void*,
                                                 const wchar_t*, ...) throw(_com_error);

HRESULT __stdcall
        _com_dispatch_raw_propget(IDispatch*, DISPID, VARTYPE, void*) throw();
HRESULT __cdecl
        _com_dispatch_raw_propput(IDispatch*, DISPID, VARTYPE, ...) throw();
HRESULT __cdecl
        _com_dispatch_raw_method(IDispatch*, DISPID, WORD, VARTYPE, void*,
*/