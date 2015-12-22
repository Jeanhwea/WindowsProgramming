// KernelObject.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <strsafe.h>

BOOL security_of_kernel_object()
{
    /* ��ȫ�Բ����ṹ��Ķ��壺
        typedef struct _SECURITY_ATTRIBUTES {
            DWORD nLength;               // SECURITY_ATTRIBUTES�ĳ���
            LPVOID lpSecurityDescriptor; // ָ��ȫ������
            BOOL bInheritHandle;         // �ӽ������Ƿ�̳и����̵��ں˶�����
        } SECURITY_ATTRIBUTES
    */
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    // ���������Ļ���������
    HANDLE hmutex1 = CreateMutex(&sa, FALSE, NULL); // �û������ᱻ�ӽ��̼̳�
    if (hmutex1 == NULL) {
        DWORD dwerr = GetLastError();
        printf("failed to create mutex1, err = %u\n", dwerr);
    }
    // ���������Ļ���������
    HANDLE hmutex2 = CreateMutex(NULL, FALSE, TEXT("Global\\JeanhweaObj"));
    if (hmutex2 == NULL) {
        DWORD dwerr = GetLastError();
        printf("failed to create mutex2, err = %u\n", dwerr);
    }
    // �����������ź�������
    HANDLE hsemaphore = CreateSemaphore(NULL, 1, 1, TEXT("Local\\JeanhweaObj2"));
    if (hsemaphore == NULL) {
        DWORD dwerr = GetLastError();
        printf("failed to create mutex2, err = %u\n", dwerr);
    }

    // �ر��ں˶���
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

    // ͨ������ID��ȡ�ỰID
    fOk = ProcessIdToSessionId(pid, &sid);

    // ���ת���ɹ������ӡ���
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

/** ����ʼǣ�
    1. �ں˶������ͨ��һ����ѵĹ���WinObj�鿴������Ҫʹ�ù���ԱȨ������WinObj
       ���ܲ鿴�ں˶���
    2. �����ں˶�����û��������򵥷����ǲ鿴�������������ǩ�����������е��ں˶���
       �Ĵ���������Ҫ�����ڴ���ʱ������ȫ������Ϣ�Ĳ��� -- SECURITY_ATTRIBUTES��
 */