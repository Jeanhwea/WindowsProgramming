// Process.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <strsafe.h>

void display_program_path(void)
{
#ifdef UNICODE
    printf("����ִ�е�·�� %S\n", _wpgmptr);
#else
    printf("����ִ�е�·�� %s\n", _pgmptr);
#endif // UNICODE
}

int _tmain(int argc, _TCHAR* argv[])
{
    display_program_path();
	return 0;
}

