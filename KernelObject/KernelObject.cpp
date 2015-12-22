// KernelObject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <strsafe.h>

BOOL security_of_kernel_object()
{
    /* 安全性参数结构体的定义：
        typedef struct _SECURITY_ATTRIBUTES {
            DWORD nLength;               // SECURITY_ATTRIBUTES的长度
            LPVOID lpSecurityDescriptor; // 指向安全描述符
            BOOL bInheritHandle;         // 子进程中是否继承父进程的内核对象句柄
        } SECURITY_ATTRIBUTES
    */
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    // 创建匿名的互斥锁对象
    HANDLE hmutex1 = CreateMutex(&sa, FALSE, NULL); // 该互斥锁会被子进程继承
    if (hmutex1 == NULL) {
        DWORD dwerr = GetLastError();
        printf("failed to create mutex1, err = %u\n", dwerr);
    }
    // 创建命名的互斥锁对象
    HANDLE hmutex2 = CreateMutex(NULL, FALSE, TEXT("Global\\JeanhweaObj"));
    if (hmutex2 == NULL) {
        DWORD dwerr = GetLastError();
        printf("failed to create mutex2, err = %u\n", dwerr);
    }
    // 创建命名的信号量对象
    HANDLE hsemaphore = CreateSemaphore(NULL, 1, 1, TEXT("Local\\JeanhweaObj2"));
    if (hsemaphore == NULL) {
        DWORD dwerr = GetLastError();
        printf("failed to create mutex2, err = %u\n", dwerr);
    }

    // 关闭内核对象
    CloseHandle(hmutex1);
    CloseHandle(hmutex2);
    CloseHandle(hsemaphore);

    return TRUE;
}

BOOL print_session_id(void)
{
    DWORD pid = GetCurrentProcessId();
    DWORD sid = 0;
    BOOL fOk = FALSE;

    // 通过进程ID获取会话ID
    fOk = ProcessIdToSessionId(pid, &sid);

    // 如果转化成功，则打印结果
    if (fOk) {
        printf("processID=%u, sessionID=%u\n", pid, sid);
    } else {
        _tprintf(TEXT("can not find session ID\n"));
    }

    return fOk;
}

int _tmain(int argc, _TCHAR* argv[])
{
    print_session_id();
    security_of_kernel_object();
	return 0;
}

/** 读书笔记：
    1. 内核对象可以通过一个免费的工具WinObj查看，必须要使用管理员权限运行WinObj
       才能查看内核对象。
    2. 区分内核对象和用户对象的最简单方法是查看创建这个函数的签名。几乎所有的内核对象
       的创建函数需要我们在创建时给出安全属性信息的参数 -- SECURITY_ATTRIBUTES。
 */