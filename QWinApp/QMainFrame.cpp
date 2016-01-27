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
