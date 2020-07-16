cmake_minimum_required (VERSION 3.6)
project (LLD)


#all executable directives shall be listed down below.
add_executable( bookStore bookStore.cpp)


target_include_directories(bookStore PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
