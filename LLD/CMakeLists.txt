cmake_minimum_required (VERSION 3.6)
project (LLD)


#all executable directives shall be listed down below.
add_executable( bookStore bookStore.cpp)
# TODO: fix dependency error
# add_executable( state_dp state_design_pattern.cpp)


target_include_directories(bookStore PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
