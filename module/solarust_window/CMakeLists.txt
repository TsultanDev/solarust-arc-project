# 1. PERTAMA: Buat target library-nya dulu!
add_library(solarust_window STATIC
    src/solarust_window.c
    src/solarust_window_types.c
)

# 2. KEDUA: Atur include directories
target_include_directories(solarust_window PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/platform
)

# 3. KETIGA: Kondisional OS untuk file sumber & library tambahan
if(WIN32)
    target_sources(solarust_window PRIVATE
        src/platform/platform_windows.c
    )

    target_link_libraries(solarust_window PRIVATE
        user32
        gdi32
        kernel32
    )
endif()
