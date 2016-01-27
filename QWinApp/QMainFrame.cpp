#include "QMainFrame.h"


QMainFrame::QMainFrame(void)
{
}


QMainFrame::~QMainFrame(void)
{
}

// message handler
LRESULT QMainFrame::OnClose(WPARAM wParam, LPARAM lParam)
{
    return ::DefWindowProc(m_hWnd, WM_CLOSE, wParam, lParam);
}

LRESULT QMainFrame::OnDestroy(WPARAM wParam, LPARAM lParam)
{
    PostQuitMessage(0);
    return TRUE;
}


LRESULT QMainFrame::OnCreate(WPARAM wParam, LPARAM lParam)
{
    // MessageBox(m_hWnd, TEXT("Receive WM_CREATE and OnCreate called"), TEXT("ÌבÊ¾"), 0);
    return TRUE;
}

