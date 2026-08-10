cmake_minimum_required(VERSION 3.10)
project(SOLARUST_ARC C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(module/solarust_window)
add_subdirectory(module/solarust)
add_subdirectory(module/app)
