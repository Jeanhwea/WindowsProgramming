// ErrorShow.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

void error_show(void)
{
    LPVOID lpMsgBuf;
    HLOCAL hlocal = NULL;

    DWORD dwError = GetLastError();
    DWORD system_locate = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT);
    
    BOOL fOk = FormatMessage(
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS |
        FORMAT_MESSAGE_ALLOCATE_BUFFER,
        NULL, dwError, system_locate, (PTSTR) &hlocal, 0, NULL);

    lpMsgBuf = (LPVOID) LocalAlloc(LMEM_ZEROINIT,
        lstrlen((LPCTSTR)hlocal) * sizeof(TCHAR));
    MessageBox(NULL, (LPCTSTR)lpMsgBuf, TEXT("Error"), MB_OK);
    printf("%s\n", lpMsgBuf);

    LocalFree(lpMsgBuf);
    ExitProcess(dwError);
}

int _tmain(int argc, _TCHAR* argv[])
{
    error_show();
    return 0;
}

