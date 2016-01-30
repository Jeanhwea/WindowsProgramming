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

LRESULT QMainFrame::OnPaint(WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(&ps);
    assert(hdc);
    {
        RECT rect;
        //::FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW));
        ::GetClientRect(m_hWnd, &rect);
        COLORREF clrOld = ::SetTextColor(hdc, RGB(255,0,0));
        TCHAR txt[] = TEXT("jeanhwea.github.io");
        ::TextOut(hdc, 0, 0, txt, _tcslen(txt));
        ::SetTextColor(hdc, clrOld);
    }
    EndPaint(&ps);

    return TRUE;
}
