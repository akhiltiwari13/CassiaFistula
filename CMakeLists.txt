cmake_minimum_required(VERSION 3.27)
project(CASSIA_FISTULA)


set(CMAKE_CXX_STANDARD 20)

MESSAGE(STATUS "***CASSIA FISTULA*** ${PROJECT_SOURCE_DIR}")


if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
    include_directories(${CMAKE_SOURCE_DIR}/osx_inc/)
endif()

if(${MACOSX})
MESSAGE("building on mac")
endif()


add_subdirectory(SOLID)
add_subdirectory(CreationalDesignPatterns)
add_subdirectory(LLD)
add_subdirectory(techniques)
add_subdirectory(matchingengine)
add_subdirectory(metaprogramming)
# add_subdirectory(fin_libs)


MESSAGE(STATUS "***CASSIA FISTULA CONFIGURATION COMPLETE***")
