#include "solarust_window_types.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#if defined (_WIN64) || defined (_WIN32)
    #include "platform/platform_windows.h"
#endif

struct SarcWindow_T{
    SarcPlatformWindow platform_window;
    bool is_running;
};

SarcWindow sarc_create_window(SarcWindowCreateInfo* pCreateInfo){
    assert(pCreateInfo->pTitle != NULL);
    assert(pCreateInfo->width >= 0);
    assert(pCreateInfo->height >= 0);

    SarcWindow window = malloc(sizeof(struct SarcWindow_T));
    if(!window){

    }

    window->platform_window = sarc_create_platform_window(pCreateInfo->pTitle, pCreateInfo->width, pCreateInfo->height);
    window->is_running = true;

    return window;
}
bool sarc_window_is_running(SarcWindow window){
    return window->is_running;
}
void sarc_window_poll_event(){
    sarc_platform_window_poll_event();
}
