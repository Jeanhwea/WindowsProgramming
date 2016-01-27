#include "QWinApp.h"
#include "QGlobal.h"

QWinApp * g_pWinApp;

QWinApp::QWinApp(void)
{
    m_pMainWnd = NULL;
    g_pWinApp = this;
}


QWinApp::~QWinApp(void)
{
}



void QWinApp::run()
{
    MSG msg;
    while (::GetMessage(&msg, NULL, 0, 0)) {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }
}

BOOL QWinApp::InitInstance()
{
    return TRUE;
}

BOOL QWinApp::ExitInstance()
{
    return TRUE;
}

