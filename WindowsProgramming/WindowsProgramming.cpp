// WindowsProgramming.cpp : 定义控制台应用程序的入口点。
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

// 全局变量
HWND gDlg = NULL;
TCHAR msg[1024] = {};



INT_PTR WINAPI cdDlgProc(HWND hwnd, UINT uMsg, WPARAM wPara, LPARAM lPara)
{
    switch (uMsg) {
        // 当用户从菜单选中一个命令项目、当一个控件发送通知消息给去父窗口
        // 或者按下一个快捷键将发送 WM_COMMAND 消息
    case WM_INITDIALOG: 
        {
            // 设置全局的窗口句柄
            gDlg = hwnd;

            // 将输入框的字符设置成5个字符
            Edit_LimitText(GetDlgItem(gDlg, IDC_EDIT_INPUT), 5);
        }
        break;
    case WM_COMMAND:
        {
            int id = LOWORD(wPara);
            switch (id) {
            case ID_EXIT:
                EndDialog(hwnd, id); // 结束窗口
                break;
            case IDC_OK: 
                {
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
                //MessageBox(hwnd, TEXT("默认消息"), TEXT("提示"), NULL);
                break;
            }
        }
        break;
    case WM_CLOSE:
        PostQuitMessage(0);
        return NULL;
    default:
        break;
    }
    return NULL;
}

// 窗口系统的入口
int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPWSTR lpCmdLine,
                       int nCmdShow )
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 从一个对话框资源中创建一个模态对话框
    DialogBox(hInstance, 
        MAKEINTRESOURCE(IDD_DIALOG),    // 把一个数字类型转换成指针类型的宏
        NULL,                           // NULL表示顶层窗口
        cdDlgProc);                     // 指定的回调函数

    return 0;
}

