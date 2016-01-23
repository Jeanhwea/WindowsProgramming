// WindowsProgramming.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <winerror.h>
#include <tchar.h>
#include <sddl.h>
#include <strsafe.h>
#include <windows.h>
#include <windowsx.h>
#include <cstring>

#include "stdafx.h"
#include "resource.h"

// ȫ�ֱ���
HWND gDlg = NULL;
TCHAR msg[1024] = {};

BOOL cbDlgInit(HWND hwnd, HWND hwnd_focus, LPARAM lpara)
{
    // ����ȫ�ֵĴ��ھ��
    gDlg = hwnd;

    // ���������ַ����ó�5���ַ�
    Edit_LimitText(GetDlgItem(gDlg, IDC_EDIT_INPUT), 5);

    return TRUE;
}

void cbDlgCmd(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{

    switch (id) {
    case ID_EXIT:
        EndDialog(hwnd, id); // ��������
        break;
    case IDC_EDIT_INPUT: {
            TCHAR line[255];
            int n;
            // Edit_GetText(GetDlgItem(gDlg, IDC_EDIT_INPUT), msg, 250);
            // n = _ttoi(msg);
            // Edit_SetText(GetDlgItem(gDlg, IDC_EDIT_OUTPUT), msg);
            n = GetDlgItemInt(hwnd, IDC_EDIT_INPUT, NULL, FALSE);
            StringCchPrintf((PTSTR)line, 250, TEXT("n=%d\r\n"), n);
            StringCchCat(msg, 1024, line);
            SetDlgItemText(gDlg, IDC_EDIT_OUTPUT, msg);
        }
        break;
    default:
        //MessageBox(hwnd, TEXT("Ĭ����Ϣ"), TEXT("��ʾ"), NULL);
        break;
    }
}

INT_PTR WINAPI cdDlgProc(HWND hwnd, UINT uMsg, WPARAM wPara, LPARAM lPara)
{
    switch (uMsg) {
        // ���û��Ӳ˵�ѡ��һ��������Ŀ����һ���ؼ�����֪ͨ��Ϣ��ȥ������
        // ���߰���һ����ݼ������� WM_COMMAND ��Ϣ
    case WM_INITDIALOG:
        return SetDlgMsgResult(hwnd, WM_INITDIALOG, 
            HANDLE_WM_INITDIALOG(hwnd, wPara, lPara, cbDlgInit));
    case WM_COMMAND:
        // SetDlgMsgResult����Ϣ������
        return SetDlgMsgResult(hwnd, WM_COMMAND, 
            HANDLE_WM_COMMAND(hwnd, wPara, lPara, cbDlgCmd));
    case WM_CLOSE:
        PostQuitMessage(0);
        return NULL;
    default:
        break;
    }
    return NULL;
}

// ����ϵͳ�����
int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPWSTR lpCmdLine,
                       int nCmdShow )
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // ��һ���Ի�����Դ�д���һ��ģ̬�Ի���
    DialogBox(hInstance, 
        MAKEINTRESOURCE(IDD_DIALOG),    // ��һ����������ת����ָ�����͵ĺ�
        NULL,                           // NULL��ʾ���㴰��
        cdDlgProc);                     // ָ���Ļص�����

    return 0;
}

