cmake_minimum_required(VERSION 3.14)
project(cassia_fistula)

set(CMAKE_CXX_STANDARD 14)

add_executable(cassia_fistula main.cpp)

target_link_libraries(cassia_fistula hiredis)