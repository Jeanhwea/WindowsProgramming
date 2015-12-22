// CharString.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

/** 8-bit �ַ���ָ��Ķ���
        typedef CHAR *PCHAR;
        typedef CHAR *PSTR;
        typedef const CHAR *PCSTR;
 */

/** 16-bit ���ַ���ָ��Ķ���
        typedef WCHAR *PWCHAR;
        typedef WCHAR *PWSTR;
        typedef const WCHAR *PWCSTR;
 */

// ��ת�ַ�����unicode�汾
BOOL str_reverse_w(PWSTR pwide_str, DWORD max_len)
{
    PWSTR pend = pwide_str + wcsnlen_s(pwide_str, max_len) - 1;
    wchar_t ch; // wchar_t ��һ�����ַ����ͣ�Ҳ����unicode����
    while (pwide_str < pend) {
        // ������һ�������һ��unicode�ַ�
        ch = *pwide_str;
        *pwide_str = *pend;
        *pend = ch;

        pwide_str++;
        pend--;
    }
    return (TRUE);
}

// ��ת�ַ�����ANSI�汾
BOOL str_reverse_a(PSTR pstr, DWORD max_len)
{
    PWSTR pwide_str;
    int nlen;
    BOOL fOk = FALSE;

    // ����pstr�ַ����ĳ���
    nlen = MultiByteToWideChar(CP_ACP, 0, pstr, max_len, NULL, 0);
    // ������̵Ķѿռ� - ��Ϊunicode�ַ����Ĵ洢
    pwide_str = (PWSTR) HeapAlloc(GetProcessHeap(), 0, nlen*sizeof(wchar_t));
    if (pwide_str == NULL)
        return fOk;

    // ��ANSI�ַ�ת����Unicode�ַ�
    MultiByteToWideChar(CP_ACP, 0, pstr, max_len, pwide_str, nlen);

    // ���÷�ת�ַ�����unicode�汾������ַ���ת
    fOk = str_reverse_w(pwide_str, max_len);

    if (fOk) {
        // ��Unicode�ַ�ת����ANSI�ַ�
        WideCharToMultiByte(CP_ACP, 0, pwide_str, max_len, 
            pstr, (int)strnlen_s(pstr, max_len), NULL, NULL);
    }

    // �ͷŽ��̶ѿռ�
    HeapFree(GetProcessHeap(), 0, pwide_str);

    return fOk;
}


int _tmain(int argc, _TCHAR* argv[])
{
    // TEXT��һ���꣬�൱�ڽ����ת���� TEXT("�ַ���") -> L"�ַ���"
    WCHAR wcstr[128] = TEXT("����һ�����ĵ�����");
    CHAR cstr[128] = "This is a c-type string";

    // ����unicode�汾���ַ�����ת
    str_reverse_w(wcstr, wcsnlen_s(wcstr, 128));

    // ����ANSI�汾���ַ�����ת
    str_reverse_a(cstr, strnlen_s(cstr, 128));


    // unicode�汾���ַ����޷�ͨ��cout��ӡ
    // std::cout << wcstr << std::endl; // ����

    // ANSI�汾���ַ������Դ�ӡ
    std::cout << cstr << std::endl; // ��ȷ

    return 0;
}


/** ����ʼǣ�
    1. Ϊ�˼����Կ��ǣ��ڵ���DLLʱ�����Կ��������汾�ģ�һ��ANSI�汾��һ��Unicode�汾��
    ����ANSI�汾�У�ֻ�Ƿ����ڴ棬ִ�б�Ҫ���ַ���ת����Ȼ����øú�����Unicode�汾��
    2. �κ��޸��ַ����ĺ���������һ����ȫ���������Ŀ���ַ��������������޷�����������
    ���ַ������ͻ�����ڴ��е������ƻ���
    3. �ڴ洢�ļ�����Ҫ�жϴ洢�ı��뷽ʽ��
 */
