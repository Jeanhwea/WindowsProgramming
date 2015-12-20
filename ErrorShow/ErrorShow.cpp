// ErrorShow.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Strsafe.h>
#include <windows.h>

void show_error(void)
{
    HLOCAL lpmsg; // HLOCAL类型可以看出LPVOID
    HLOCAL lpmsgbuf;
    HLOCAL hlocal=NULL;

    DWORD dwerr = GetLastError();
    DWORD dwlocate = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT);
    
    BOOL fOk = FormatMessage(
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS |
        FORMAT_MESSAGE_ALLOCATE_BUFFER,
        NULL, dwerr, dwlocate, (PTSTR) &hlocal, 0, NULL);

    if (fOk) {
        SIZE_T smsg = (lstrlen((LPCTSTR)hlocal)+1) * sizeof(TCHAR);
        lpmsg = (HLOCAL) LocalAlloc(LMEM_ZEROINIT, smsg);
        StringCchPrintf((PTSTR)lpmsg, LocalSize(lpmsg), TEXT("%s"), hlocal);
        MessageBox(NULL, (LPCTSTR)lpmsg, TEXT("Prompt"), MB_OK);
        LocalFree(lpmsg);
    }

    ExitProcess(dwerr);
}

int _tmain(int argc, _TCHAR* argv[])
{
    // 故意设置一个系统错误
    SetLastError(ERROR_FILE_NOT_FOUND);

    show_error(); // 捕捉系统错误

    return 0;
}

