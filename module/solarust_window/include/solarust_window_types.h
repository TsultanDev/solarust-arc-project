#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct SarcWindow_T* SarcWindow;

typedef struct SarcWindowCreateInfo{
    SarcWindow parent;
    char* pTitle;
    uint32_t width;
    uint32_t height;
} SarcWindowCreateInfo;

SarcWindow sarc_create_window(SarcWindowCreateInfo* pCreateInfo);
bool sarc_window_is_running(SarcWindow window);
void sarc_window_poll_event();
