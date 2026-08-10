add_library(solarust STATIC
  src/solarust.c
)

target_include_directories(solarust PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(solarust PUBLIC
    solarust_window
)
