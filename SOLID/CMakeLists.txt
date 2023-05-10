cmake_minimum_required (VERSION 3.6)
project (SOLID_DESIGN_PRINCIPALS)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

#all executable directives shall be listed down below.
add_executable( single_responsibility source/single_responsibility.cpp)
add_executable( open_close source/open_close.cpp)
add_executable( liskov_substitution source/liskov_substitution.cpp)
add_executable( interface_segregation source/interface_segregation.cpp)

add_executable( dependency_inversion source/dependency_inversion.cpp)
target_include_directories(dependency_inversion PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(dependency_inversion PRIVATE ${Boost_LIBRARIES})

#building specification_filter as a header only (interface) libarary.
add_library( specification_filter INTERFACE )
target_include_directories(specification_filter INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/specification_filter.h")
