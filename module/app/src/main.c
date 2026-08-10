#include "solarust.h"
#include "solarust_window_types.h"
#include <stdio.h>

int main(void){
    SarcWindowCreateInfo window_info = {0};
    window_info.parent = NULL;
    window_info.pTitle = "App";
    window_info.width = 800;
    window_info.height = 600;
    SarcWindow window = sarc_create_window(&window_info);

    while(sarc_window_is_running(window)){
        sarc_window_poll_event();
    }
    printf("App Exit Successfully!!");
    return 0;
}
