# 1. PERTAMA: Buat target library-nya dulu!
add_library(solarust_system
    src/solarust_system.c
)

# 2. KEDUA: Atur include directories
target_include_directories(solarust_system PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/platform
)

# 3. KETIGA: Kondisional OS untuk file sumber & library tambahan
if(WIN32)
    target_sources(solarust_system PRIVATE
        src/platform/windows.c
    )

    target_link_libraries(solarust_system PRIVATE
        user32
        gdi32
        kernel32
    )
endif()
