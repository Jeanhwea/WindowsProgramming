#pragma once
#include "stdafx.h"

class QWnd
{
public:
    QWnd(void);
    ~QWnd(void);


public:
    BOOL ShowWindow(int nShowCmd);
    BOOL UpdateWindow();
    BOOL DestroyWindow();

    virtual BOOL CreateEx(
        DWORD     dwExStyle,
        LPCTSTR   lpClassName,
        LPCTSTR   lpWindowName,
        DWORD     dwStyle,
        int       x = CW_USEDEFAULT,
        int       y = CW_USEDEFAULT,
        int       nWidth = CW_USEDEFAULT,
        int       nHeight = CW_USEDEFAULT,
        HWND      hWndParent = NULL,
        HMENU     hMenu = NULL,
        LPVOID    lpParam = NULL
    );

private:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    static LRESULT CALLBACK cbWinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
    virtual LRESULT WinProc(UINT uMsg, WPARAM wParam, LPARAM lParam); 

    // message handle
    virtual LRESULT OnClose(WPARAM wParam, LPARAM lParam);
    virtual LRESULT OnDestroy(WPARAM wParam, LPARAM lParam);

public:
    HWND m_hWnd;
};

