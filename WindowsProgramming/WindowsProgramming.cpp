// WindowsProgramming.cpp : 定义控制台应用程序的入口点。
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
        EndDialog(hwnd, id); // 结束窗口
        break;
    }
}

INT_PTR WINAPI cb_dlg_proc(HWND hwnd, UINT umsg, WPARAM wpara, LPARAM lpara)
{
    switch (umsg) {
        // 当用户从菜单选中一个命令项目、当一个控件发送通知消息给去父窗口
        // 或者按下一个快捷键将发送 WM_COMMAND 消息
    case WM_INITDIALOG:
        return SetDlgMsgResult(hwnd, WM_INITDIALOG, 
            HANDLE_WM_INITDIALOG(hwnd, wpara, lpara, cb_dlg_init));
        break;
    case WM_COMMAND:
        // SetDlgMsgResult是消息分流器
        return SetDlgMsgResult(hwnd, WM_COMMAND, 
            HANDLE_WM_COMMAND(hwnd, wpara, lpara, cb_dlg_cmd));
        exit(0);
        break;
    default:
        break;
    }
    return NULL;
}

// 窗口系统的入口
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                       _In_opt_ HINSTANCE hPrevInstance,
                       _In_ LPWSTR lpCmdLine,
                       _In_ int nShowCmd )
{
    // 从一个对话框资源中创建一个模态对话框
    DialogBox(hInstance, 
        MAKEINTRESOURCE(IDD_DIALOG), // 把一个数字类型转换成指针类型的宏
        NULL,                           // NULL表示顶层窗口
        cb_dlg_proc);                    // 指定的回调函数

    return 0;
}