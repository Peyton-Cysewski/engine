#include <thread>

#include "os.h"

// Constructor and Destructor
OS::OS() {}
OS::~OS() {}
// member functions
LRESULT CALLBACK OS::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }
    return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
int OS::RegisterWindowClass()
{
    const wchar_t kClassName[] = L"Placeholder Window Class";
    wc_.lpfnWndProc = WindowProc;
    wc_.hInstance = 0; // hInstance <-?
    wc_.lpszClassName = kClassName;
    RegisterClass(&wc_);
    return 0;
}
int OS::CreateOSWindow()
{
    const wchar_t kClassName[] = L"Placeholder Window Class";

    hwnd_ = CreateWindowEx(
        0,                              // dwExSyle        Optional window styles.
        kClassName,                     // lpClassName     Window class
        L"Learn to Program Windows",    // lpWindowName    Window text
        WS_OVERLAPPEDWINDOW,            // dwStyle         Window style

        // Size and position
        CW_USEDEFAULT,                  // X
        CW_USEDEFAULT,                  // Y
        CW_USEDEFAULT,                  // nWidth
        CW_USEDEFAULT,                  // nHeight

        HWND_MESSAGE,                   // hWndParent      Parent window    
        NULL,                           // hMenu           Menu
        NULL,                           // hInstance       Instance handle
        NULL                            // lpParam         Additional application data
    );

    if (hwnd_ == NULL)
    {
        return 1;
    }
}
int OS::MessageLoop()
{
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
void OS::test()
{
    OS::RegisterWindowClass();
    OS::CreateOSWindow();
    OS::MessageLoop();
}