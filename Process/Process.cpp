// Process.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <strsafe.h>

// 获取当前执行的程序的所在路径
int display_program_path(void)
{
#ifdef UNICODE
    printf("程序执行的路径 %S\n", _get_wpgmptr);
#else
    printf("程序执行的路径 %s\n", _get_pgmptr);
#endif // UNICODE
    return 0;
}

// 获取当前执行的程序的基地址
int dump_module()
{
    // 传入NULL，则返回当前应用的基地址
    HMODULE hmod = GetModuleHandle(NULL);
    printf("running application base = 0x%x\n", hmod);


    // 使用GetModuleHandleEx调用
    // GetModuleHandleEx会使用传入的函数指针，来找函数所在模块的基地址
    hmod = NULL;
    GetModuleHandleEx(
        GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
        (PCTSTR) dump_module,
        &hmod);
    printf("GetModuleHandleEx = 0x%x\n", hmod);
    return 0;
}

// 获取进程的环境变量
int dump_envstr() {
    // 获取完整的环境块
    PTSTR penv = GetEnvironmentStrings();
    // 环境变量块的内存通常如下：
    // =::=::\
    // Var1=Value1\0
    // Var2=Value2\0
    // Var3=Value3\0
    // ...
    // VarN=ValueN\0\0

    if (penv == NULL) {
        printf("GetEnvironmentStrings failed (%d)\n", GetLastError()); 
        return 0;
    }

    LPTSTR lpszVariable = (LPTSTR) penv;
    // 依次打印环境变量的值
    while (*lpszVariable) {
        _tprintf(TEXT("%s\n"), lpszVariable);
        lpszVariable += lstrlen(lpszVariable) + 1;
    }

    // 释放完整的环境块
    FreeEnvironmentStrings(penv);
    return 0;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* env[])
{
    dump_envstr();
    return 0;
}

