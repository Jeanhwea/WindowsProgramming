// Process.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <strsafe.h>

// ��ȡ��ǰִ�еĳ��������·��
int display_program_path(void)
{
#ifdef UNICODE
    printf("����ִ�е�·�� %S\n", _get_wpgmptr);
#else
    printf("����ִ�е�·�� %s\n", _get_pgmptr);
#endif // UNICODE
    return 0;
}

// ��ȡ��ǰִ�еĳ���Ļ���ַ
int dump_module()
{
    // ����NULL���򷵻ص�ǰӦ�õĻ���ַ
    HMODULE hmod = GetModuleHandle(NULL);
    printf("running application base = 0x%x\n", hmod);


    // ʹ��GetModuleHandleEx����
    // GetModuleHandleEx��ʹ�ô���ĺ���ָ�룬���Һ�������ģ��Ļ���ַ
    hmod = NULL;
    GetModuleHandleEx(
        GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
        (PCTSTR) dump_module,
        &hmod);
    printf("GetModuleHandleEx = 0x%x\n", hmod);
    return 0;
}

// ��ȡ���̵Ļ�������
int dump_envstr() {
    // ��ȡ�����Ļ�����
    PTSTR penv = GetEnvironmentStrings();
    // ������������ڴ�ͨ�����£�
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
    // ���δ�ӡ����������ֵ
    while (*lpszVariable) {
        _tprintf(TEXT("%s\n"), lpszVariable);
        lpszVariable += lstrlen(lpszVariable) + 1;
    }

    // �ͷ������Ļ�����
    FreeEnvironmentStrings(penv);
    return 0;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* env[])
{
    dump_envstr();
    return 0;
}

