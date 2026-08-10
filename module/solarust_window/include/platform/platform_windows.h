#pragma once

#include <stdint.h>
#if defined (_WIN64) || defined(_WIN32)
    #include <windows.h>

    typedef struct SarcPlatformWindow_T* SarcPlatformWindow;
    SarcPlatformWindow sarc_create_platform_window(char* pTitle, uint32_t width, uint32_t height);
    void sarc_platform_window_poll_event();

#elif defined(__linux__) || defined(__APPLE__)

#endif
