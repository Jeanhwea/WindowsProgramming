// WindowsProgramming.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <winerror.h>
#include <tchar.h>
#include <sddl.h>
#include <strsafe.h>
#include <windows.h>
#include <windowsx.h>

#include "stdafx.h"
#include "resource.h"


BOOL cb_dlg_init(HWND hwnd, HWND hwnd_focus, LPARAM lpara)
{
    return TRUE;
}

void cb_dlg_cmd(HWND hwnd, int id, HWND hwnd_ctl, UINT codeNotify)
{
    switch (id) {
    default:
        EndDialog(hwnd, id); // ��������
        break;
    }
}

INT_PTR WINAPI cb_dlg_proc(HWND hwnd, UINT umsg, WPARAM wpara, LPARAM lpara)
{
    switch (umsg) {
        // ���û��Ӳ˵�ѡ��һ��������Ŀ����һ���ؼ�����֪ͨ��Ϣ��ȥ������
        // ���߰���һ����ݼ������� WM_COMMAND ��Ϣ
    case WM_INITDIALOG:
        return SetDlgMsgResult(hwnd, WM_INITDIALOG, 
            HANDLE_WM_INITDIALOG(hwnd, wpara, lpara, cb_dlg_init));
        break;
    case WM_COMMAND:
        // SetDlgMsgResult����Ϣ������
        return SetDlgMsgResult(hwnd, WM_COMMAND, 
            HANDLE_WM_COMMAND(hwnd, wpara, lpara, cb_dlg_cmd));
        exit(0);
        break;
    default:
        break;
    }
    return NULL;
}

// ����ϵͳ�����
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                       _In_opt_ HINSTANCE hPrevInstance,
                       _In_ LPWSTR lpCmdLine,
                       _In_ int nShowCmd )
{
    // ��һ���Ի�����Դ�д���һ��ģ̬�Ի���
    DialogBox(hInstance, 
        MAKEINTRESOURCE(IDD_DIALOG), // ��һ����������ת����ָ�����͵ĺ�
        NULL,                           // NULL��ʾ���㴰��
        cb_dlg_proc);                    // ָ���Ļص�����

    return 0;
}