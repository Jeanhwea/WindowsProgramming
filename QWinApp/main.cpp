#include "stdafx.h"
#include "QGlobal.h"
#include "QWinApp.h"

int WINAPI _tWinMain( _In_ HINSTANCE hInstance, 
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPTSTR lpCmdLine,
                      _In_ int nShowCmd)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    QWinApp * pWinApp = g_pWinApp;
    assert(pWinApp);

    if (pWinApp->InitInstance()) {
        pWinApp->run();
        pWinApp->ExitInstance();
    }

    return 0;
}

