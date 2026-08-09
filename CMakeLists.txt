cmake_minimum_required(VERSION 3.10)
project(SOLARUST_ARC C)
set_target_properties(solarust_system PROPERTIES LINKER_LANGUAGE C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(module/app)
add_subdirectory(module/solarust_system)
