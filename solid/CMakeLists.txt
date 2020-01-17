cmake_minimum_required (VERSION 3.6)
project (SOLID_DESIGN_PRINCIPALS)


#all executable directives shall be listed down below.
add_executable( single_responsibility source/single_responsibility.cpp)
add_executable( open_close source/open_close.cpp)
add_executable( liskov_substitution source/liskov_substitution.cpp)
add_executable( interface_segregation source/interface_segregation)
add_executable( dependency_inversion source/dependency_inversion.cpp)


target_include_directories(dependency_inversion PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
