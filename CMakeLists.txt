cmake_minimum_required(VERSION 3.10)
project(CASSIA_FISTULA)

set(CMAKE_CXX_STANDARD 14)

MESSAGE(STATUS "***CASSIA FISTULA*** ${PROJECT_SOURCE_DIR}") 

add_subdirectory(solid)
add_subdirectory(builder_pattern)
add_subdirectory(graph_impl)

MESSAGE(STATUS "***CASSIA FISTULA CONFIGURATION COMPLETE***")

