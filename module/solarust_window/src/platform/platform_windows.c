#include "platform/platform_windows.h"
#include <stdlib.h>
#include <wchar.h>
#include <winuser.h>

struct SarcPlatformWindow_T{
    HINSTANCE handle;
    HWND window;
};

LRESULT CALLBACK SolarustWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    // WAJIB: Biarkan Windows menangani pesan lainnya
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

SarcPlatformWindow sarc_create_platform_window(char* pTitle, uint32_t width, uint32_t height){
    HINSTANCE instance = GetModuleHandleW(NULL);

    WNDCLASSEXW window_class = {0};
    window_class.cbSize = sizeof(WNDCLASSEXW);
    window_class.lpszClassName = L"SolarustWindowClass";
    window_class.hInstance = instance;
    window_class.lpfnWndProc = SolarustWindowProc;
    window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    window_class.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClassExW(&window_class);

    wchar_t pWTitle[256] = {0};
    MultiByteToWideChar(CP_UTF8, 0, pTitle, -1, pWTitle, 256);

    HWND window = CreateWindowExW(0, L"SolarustWindowClass", pWTitle, WS_OVERLAPPEDWINDOW, 0, 0, width, height, NULL, NULL, instance, NULL);
    if(!window){

    }
    ShowWindow(window, SW_SHOW);
    UpdateWindow(window);

    SarcPlatformWindow platform_window = malloc(sizeof(struct SarcPlatformWindow_T));
    if(!platform_window){

    }
    platform_window->handle = instance;
    platform_window->window = window;
    return platform_window;
}
void sarc_platform_window_poll_event(){
    MSG msg = {0};
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0) {
        TranslateMessage(&msg); // Menerjemahkan input keyboard
        DispatchMessage(&msg);  // Mengirim pesan ke SolarustWindowProc
    }
}
