// Process.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <strsafe.h>

void display_program_path(void)
{
#ifdef UNICODE
    printf("程序执行的路径 %S\n", _wpgmptr);
#else
    printf("程序执行的路径 %s\n", _pgmptr);
#endif // UNICODE
}

int _tmain(int argc, _TCHAR* argv[])
{
    display_program_path();
	return 0;
}

