#include "QDemoWinApp.h"
#include "QMainFrame.h"


QDemoWinApp::QDemoWinApp(void)
{
}


QDemoWinApp::~QDemoWinApp(void)
{
}

QDemoWinApp * theApp = new QDemoWinApp;


BOOL QDemoWinApp::InitInstance()
{
    QMainFrame* pMainWnd = new QMainFrame;
    assert(pMainWnd);

    m_pMainWnd = pMainWnd;

    BOOL bRet = pMainWnd->CreateEx(0, TEXT("jeanhwea.github.io"), TEXT("Jeanhwea"), WS_OVERLAPPEDWINDOW);
    if (!bRet) {
        MessageBox(NULL, TEXT("´´½¨´°¿ÚÊ§°Ü"), TEXT("´íÎó"), 0);
        return FALSE;
    }

    pMainWnd->ShowWindow(SW_SHOW);
    pMainWnd->UpdateWindow();

    return TRUE;
}

BOOL QDemoWinApp::ExitInstance()
{
    if (m_pMainWnd) {
        delete m_pMainWnd;
        m_pMainWnd = NULL;
    }
    return TRUE;
}
