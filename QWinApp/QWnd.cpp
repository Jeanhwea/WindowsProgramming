#include "QWnd.h"


QWnd::QWnd(void)
{
    m_hWnd = NULL;
}


QWnd::~QWnd(void)
{
}

LRESULT CALLBACK QWnd::cbWinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_CREATE || uMsg == WM_NCCREATE) {
        LPCREATESTRUCT pCs = (LPCREATESTRUCT) lParam;
        if (pCs) {
            QWnd * pWnd = (QWnd *) pCs->lpCreateParams;
            if (pWnd) {
                pWnd->m_hWnd = hwnd;
                return pWnd->WinProc(uMsg, wParam, lParam);
            }
        }
    }

    QWnd * pWnd = (QWnd *) GetWindowLong(hwnd, GWL_USERDATA);
    if (pWnd) {
        return pWnd->WinProc(uMsg, wParam, lParam);
    }

    return ::DefWindowProc(hwnd, uMsg, wParam, lParam);
}
LRESULT QWnd::WinProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_CLOSE:
        OnClose(wParam, lParam);
        break;

    case WM_DESTROY:
        OnDestroy(wParam, lParam);
        break;

    default:
        break;
    }
    // DefWindowProc: default window messages handling
    return ::DefWindowProc(m_hWnd, uMsg, wParam, lParam);
}

BOOL QWnd::PreCreateWindow(CREATESTRUCT& cs)
{
    WNDCLASSEX wcex;
    wcex.cbSize        = sizeof(WNDCLASSEX);

    // ��ѯ���������Ϣ
    BOOL bRet = ::GetClassInfoEx(cs.hInstance, cs.lpszClass, &wcex);
    // �����ѯ������ֱ�ӷ���
    if (bRet) {
        return TRUE;
    }

    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = cbWinProc;
    wcex.cbClsExtra    = 0;
    wcex.cbWndExtra    = 0;
    wcex.hInstance     = cs.hInstance;
    wcex.hIcon         = ::LoadIcon(NULL, IDI_APPLICATION);
    wcex.hIconSm       = ::LoadIcon(NULL, IDI_APPLICATION);
    wcex.hbrBackground = (HBRUSH) ::GetStockObject(GRAY_BRUSH);
    wcex.hCursor       = (HCURSOR) ::LoadCursor(NULL, IDC_ARROW);
    wcex.lpszMenuName  = NULL;
    wcex.lpszClassName = cs.lpszClass;

    // ע�ᴰ����
    bRet = ::RegisterClassEx(&wcex);

    return bRet;
}

BOOL QWnd::CreateEx(
    DWORD     dwExStyle,
    LPCTSTR   lpClassName,
    LPCTSTR   lpWindowName,
    DWORD     dwStyle,
    int       x,
    int       y,
    int       nWidth,
    int       nHeight,
    HWND      hWndParent,
    HMENU     hMenu,
    LPVOID    lpParam)
{
    // ��ȡ��ǰʵ��
    HINSTANCE hInstance = (HINSTANCE) ::GetModuleHandle(NULL);
    assert(hInstance);

    CREATESTRUCT cs;
    cs.dwExStyle = dwExStyle;
    cs.lpszClass = lpClassName;
    cs.lpszName = lpWindowName;
    cs.style = dwStyle;
    cs.x = x;
    cs.y = y;
    cs.cx = nWidth;
    cs.cy = nHeight;
    cs.hwndParent = hWndParent;
    cs.hMenu = hMenu;
    cs.hInstance = hInstance;
    cs.lpCreateParams = lpParam;

    BOOL bRet = PreCreateWindow(cs);
    if (!bRet) {
        MessageBox(NULL, TEXT("ע�ᴰ����ʧ��"), TEXT("����"), 0);
        return FALSE;
    }

    HWND hwnd = ::CreateWindowEx(cs.dwExStyle, cs.lpszClass, cs.lpszName, cs.style, cs.x, cs.y,
        cs.cx, cs.cy , cs.hwndParent, cs.hMenu, cs.hInstance, cs.lpCreateParams);

    if (hwnd == NULL) {
        return FALSE;
    }
    m_hWnd = hwnd;

    // ��m_hWnd��������this�������û��ռ�
    ::SetWindowLong(m_hWnd, GWL_USERDATA, (LONG)this);

    return TRUE;
}

BOOL QWnd::ShowWindow(int nShowCmd)
{
    assert(m_hWnd);
    return ::ShowWindow(m_hWnd, nShowCmd);
}

BOOL QWnd::UpdateWindow()
{
    assert(m_hWnd);
    return ::UpdateWindow(m_hWnd);
}

BOOL QWnd::DestroyWindow()
{
    assert(m_hWnd);
    return ::DestroyWindow(m_hWnd);
}

// message handler
LRESULT QWnd::OnClose(WPARAM wParam, LPARAM lParam)
{
    return ::DefWindowProc(m_hWnd, WM_CLOSE, wParam, lParam);
}

LRESULT QWnd::OnDestroy(WPARAM wParam, LPARAM lParam)
{
    return ::DefWindowProc(m_hWnd, WM_DESTROY, wParam, lParam);
}

