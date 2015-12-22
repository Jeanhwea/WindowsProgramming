// CharString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

/** 8-bit 字符的指针的定义
        typedef CHAR *PCHAR;
        typedef CHAR *PSTR;
        typedef const CHAR *PCSTR;
 */

/** 16-bit 宽字符的指针的定义
        typedef WCHAR *PWCHAR;
        typedef WCHAR *PWSTR;
        typedef const WCHAR *PWCSTR;
 */

// 反转字符串的unicode版本
BOOL str_reverse_w(PWSTR pwide_str, DWORD max_len)
{
    PWSTR pend = pwide_str + wcsnlen_s(pwide_str, max_len) - 1;
    wchar_t ch; // wchar_t 是一个宽字符类型，也就是unicode类型
    while (pwide_str < pend) {
        // 交换第一个和最后一个unicode字符
        ch = *pwide_str;
        *pwide_str = *pend;
        *pend = ch;

        pwide_str++;
        pend--;
    }
    return (TRUE);
}

// 反转字符串的ANSI版本
BOOL str_reverse_a(PSTR pstr, DWORD max_len)
{
    PWSTR pwide_str;
    int nlen;
    BOOL fOk = FALSE;

    // 计算pstr字符串的长度
    nlen = MultiByteToWideChar(CP_ACP, 0, pstr, max_len, NULL, 0);
    // 申请进程的堆空间 - 作为unicode字符串的存储
    pwide_str = (PWSTR) HeapAlloc(GetProcessHeap(), 0, nlen*sizeof(wchar_t));
    if (pwide_str == NULL)
        return fOk;

    // 将ANSI字符转换成Unicode字符
    MultiByteToWideChar(CP_ACP, 0, pstr, max_len, pwide_str, nlen);

    // 调用反转字符串的unicode版本来完成字符反转
    fOk = str_reverse_w(pwide_str, max_len);

    if (fOk) {
        // 将Unicode字符转换回ANSI字符
        WideCharToMultiByte(CP_ACP, 0, pwide_str, max_len, 
            pstr, (int)strnlen_s(pstr, max_len), NULL, NULL);
    }

    // 释放进程堆空间
    HeapFree(GetProcessHeap(), 0, pwide_str);

    return fOk;
}


int _tmain(int argc, _TCHAR* argv[])
{
    // TEXT是一个宏，相当于将这个转换： TEXT("字符串") -> L"字符串"
    WCHAR wcstr[128] = TEXT("这是一个中文的数组");
    CHAR cstr[128] = "This is a c-type string";

    // 调用unicode版本的字符串反转
    str_reverse_w(wcstr, wcsnlen_s(wcstr, 128));

    // 调用ANSI版本的字符串反转
    str_reverse_a(cstr, strnlen_s(cstr, 128));


    // unicode版本的字符串无法通过cout打印
    // std::cout << wcstr << std::endl; // 错误

    // ANSI版本的字符串可以打印
    std::cout << cstr << std::endl; // 正确

    return 0;
}


/** 读书笔记：
    1. 为了兼容性考虑，在导出DLL时，可以考虑两个版本的，一个ANSI版本和一个Unicode版本。
    其中ANSI版本中，只是分配内存，执行必要的字符串转换，然后调用该函数的Unicode版本。
    2. 任何修改字符串的函数都存在一个安全隐患：如果目标字符缓冲区不够大，无法容纳所生的
    的字符串，就会造成内存中的数据破坏。
    3. 在存储文件是需要判断存储的编码方式。
 */
