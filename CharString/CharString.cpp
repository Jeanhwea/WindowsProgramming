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


int _tmain(int argc, _TCHAR* argv[])
{
    WCHAR wc[128] = TEXT("����һ�����ĵ�����");


	return 0;
}


/** ����ʼǣ�
    1. Ϊ�˼����Կ��ǣ��ڵ���DLLʱ�����Կ��������汾�ģ�һ��ANSI�汾��һ��Unicode�汾��
       ����ANSI�汾�У�ֻ�Ƿ����ڴ棬ִ�б�Ҫ���ַ���ת����Ȼ����øú�����Unicode�汾��
    2. �κ��޸��ַ����ĺ���������һ����ȫ���������Ŀ���ַ��������������޷�����������
       ���ַ������ͻ�����ڴ��е������ƻ���
 */
