#pragma once
#include "stdafx.h"

class QWnd
{
public:
    QWnd(void);
    ~QWnd(void);

public:
    HWND m_hWnd;


private:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    static LRESULT CALLBACK cbWinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// message handle
public:
    virtual LRESULT OnClose(WPARAM wParam, LPARAM lParam) = 0;
    virtual LRESULT OnDestroy(WPARAM wParam, LPARAM lParam) = 0;
    virtual LRESULT OnCreate(WPARAM wParam, LPARAM lParam) = 0;
    virtual LRESULT OnPaint(WPARAM wParam, LPARAM lParam) = 0;

public:
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
    virtual LRESULT WinProc(UINT uMsg, WPARAM wParam, LPARAM lParam); 
    BOOL ShowWindow(int nShowCmd);
    BOOL UpdateWindow();
    BOOL DestroyWindow();
    HDC BeginPaint(PAINTSTRUCT *lpPaint);
    BOOL EndPaint(PAINTSTRUCT * lpPaint);
};

