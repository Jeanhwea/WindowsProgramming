
// SingleDoc.h : SingleDoc Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
    #error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSingleDocApp:
// �йش����ʵ�֣������ SingleDoc.cpp
//

class CSingleDocApp : public CWinApp
{
public:
    CSingleDocApp();


// ��д
public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();

// ʵ��
    afx_msg void OnAppAbout();
    DECLARE_MESSAGE_MAP()
};

extern CSingleDocApp theApp;
