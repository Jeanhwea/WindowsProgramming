
// FirstMFCDlg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
    #error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CFirstMFCDlgApp:
// �йش����ʵ�֣������ FirstMFCDlg.cpp
//

class CFirstMFCDlgApp : public CWinApp
{
public:
    CFirstMFCDlgApp();

// ��д
public:
    virtual BOOL InitInstance();

// ʵ��

    DECLARE_MESSAGE_MAP()
};

extern CFirstMFCDlgApp theApp;