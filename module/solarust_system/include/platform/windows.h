#include <stdlib.h>

#if defined (_WIN64)
    #include <windows.h>

    typedef struct SolarustSystemPlatformEntry{
        HINSTANCE handle_instance;
    } SolarustSystemPlatformEntry;

    SolarustSystemPlatformEntry* solarust_system_platform_init(){
        HINSTANCE instance = GetModuleHandleW(NULL);
        LPSTR lpCmdLine = GetCommandLineA();

        SolarustSystemPlatformEntry* entry = (SolarustSystemPlatformEntry*)malloc(sizeof(SolarustSystemPlatformEntry));

        return
    }



#elif defined(__linux__) || defined(__APPLE__)

#endif
