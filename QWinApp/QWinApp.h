#pragma once
#include "stdafx.h"

class QWinApp
{
public:
    QWinApp(void);
    ~QWinApp(void);

public:
    virtual BOOL InitInstance();
    virtual BOOL ExitInstance();
    virtual void run();

public:
    LPVOID m_pMainWnd;
};

