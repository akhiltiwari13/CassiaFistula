cmake_minimum_required(VERSION 3.10)
project(CASSIA_FISTULA)

set(CMAKE_CXX_STANDARD 17)

MESSAGE(STATUS "***CASSIA FISTULA*** ${PROJECT_SOURCE_DIR}")

add_subdirectory(SOLID)
add_subdirectory(CreationalDesignPatterns)
add_subdirectory(LLD)

MESSAGE(STATUS "***CASSIA FISTULA CONFIGURATION COMPLETE***")
