#include <comdef.h>

_variant_t vtMissing(DISP_E_PARAMNOTFOUND, VT_ERROR);

// Convert char * to BSTR
//
BSTR __stdcall _com_util::ConvertStringToBSTR(const char* pSrc) throw(_com_error) {
   BSTR wsOut = NULL;
   if( NULL != pSrc) {
      int cwch = ::MultiByteToWideChar(CP_ACP, 0, pSrc, -1, NULL, 0);
      if(0 != cwch) {
         wsOut = ::SysAllocStringLen(NULL, cwch);
         if (NULL == wsOut) {
            _com_issue_error(E_OUTOFMEMORY);
         }
         if(0 == ::MultiByteToWideChar(CP_ACP, 0, pSrc, -1, wsOut, cwch)) {
             DWORD lerr = ::GetLastError();
             ::SysFreeString(wsOut);//must clean up
             wsOut = NULL;
             _com_issue_error(HRESULT_FROM_WIN32(lerr));
         }
      }
   }
   return wsOut;
} //end of func

// Convert BSTR to char *
//
char* __stdcall _com_util::ConvertBSTRToString(BSTR pSrc) throw(_com_error) {
   char* szOut = NULL;
   if(NULL != pSrc) {
      //convert even embeded NULL
      DWORD cwch = ::SysStringLen(pSrc);
      int cb = ::WideCharToMultiByte(CP_ACP, 0, pSrc, cwch + 1, NULL, 0, 0, 0);
      if(cb != 0) {
         szOut = ::new char[cb];
         if (NULL == szOut) {
             _com_issue_error(E_OUTOFMEMORY);
         }
         szOut[cb - 1]  = '\0';
         if(0 == ::WideCharToMultiByte(CP_ACP, 0, pSrc, cwch + 1, szOut, cb, 0, 0)) {
             ::delete []szOut;//clean up if failed;
             szOut = NULL;
             _com_issue_error(HRESULT_FROM_WIN32(::GetLastError()));
         }
      }
   }
   return szOut;
}  //end of func

