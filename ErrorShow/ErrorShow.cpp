// ErrorShow.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Strsafe.h>
#include <windows.h>

void show_error(void)
{
    // HLOCAL类型可以看成LPVOID
    HLOCAL hlocal=NULL;
    // 获取系统的最后一个错误
    DWORD dwerr = GetLastError();
    DWORD dwlocate = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT);
    
    BOOL fOk = FormatMessage(
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS |
        FORMAT_MESSAGE_ALLOCATE_BUFFER,
        NULL, dwerr, dwlocate, (PTSTR) &hlocal, 0, NULL);


    if (fOk) {// 如果错误消息获得成功,则使用对话框将消息显示出来
        SIZE_T smsg = (lstrlen((LPCTSTR)hlocal)+1) * sizeof(TCHAR);
        HLOCAL lpmsg = (HLOCAL) LocalAlloc(LMEM_ZEROINIT, smsg);
        StringCchPrintf((PTSTR)lpmsg, LocalSize(lpmsg), TEXT("%s"), hlocal);
        MessageBox(NULL, (LPCTSTR)lpmsg, TEXT("Prompt"), MB_OK);
        LocalFree(lpmsg);
    }

    // 以最后一个错误号退出进程
    ExitProcess(dwerr);
}

int _tmain(int argc, _TCHAR* argv[])
{
    // 故意设置一个系统错误
    SetLastError(ERROR_FILE_NOT_FOUND);

    show_error(); // 捕捉系统错误

    return 0;
}

/** 读书笔记：
    1. 当一个程序面临崩溃时，我们需要调用GetLastError函数使得程序优先地告诉用户崩溃的原因。
 */