
#if defined (_WIN64)
    #include <windows.h>
    #include "platform/windows.h"
#elif defined(__linux__) || defined(__APPLE__)
    #include <unistd.h>
#endif

typedef struct SolarustSystemEntry{
    SolarustSystemPlatformEntry* pEntry;
} SolarustSystemEntry;
