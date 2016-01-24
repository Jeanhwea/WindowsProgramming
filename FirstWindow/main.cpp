#include <windows.h>

LRESULT CALLBACK cbWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;
    default:
        break;
    }
    // DefWindowProc: default window messages handling
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = TEXT("Jeanhwea's First Window");

    // if has opened a instance, then exit
    HWND lastwnd = FindWindow(CLASS_NAME, NULL);
    if (lastwnd) return 0;

    WNDCLASS wc = { };

    wc.lpfnWndProc   = cbWindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                                 // Optional window styles.
        CLASS_NAME,                        // Window class
        TEXT("Learn to Program Windows"),  // Window text
        WS_OVERLAPPEDWINDOW,               // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);


    // Run the message loop.
    MSG msg = { };
    BOOL bRet;
    while (bRet = GetMessage(&msg, NULL, 0, 0)) {
        if (bRet == -1 ) {
            // add some text to handle fail of get a message
        } else {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}



