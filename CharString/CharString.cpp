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


int _tmain(int argc, _TCHAR* argv[])
{
    WCHAR wc[128] = TEXT("这是一个中文的数组");


	return 0;
}


/** 读书笔记：
    1. 为了兼容性考虑，在导出DLL时，可以考虑两个版本的，一个ANSI版本和一个Unicode版本。
       其中ANSI版本中，只是分配内存，执行必要的字符串转换，然后调用该函数的Unicode版本。
    2. 任何修改字符串的函数都存在一个安全隐患：如果目标字符缓冲区不够大，无法容纳所生的
       的字符串，就会造成内存中的数据破坏。
 */
