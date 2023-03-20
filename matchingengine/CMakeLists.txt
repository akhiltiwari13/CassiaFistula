cmake_minimum_required(VERSION 3.10)
project(exchange_simulator)                                                                                                                                          
set(CMAKE_CXX_STANDARD 17)                                                                                                                                                

MESSAGE(STATUS "***exchange_simulator*** ${PROJECT_SOURCE_DIR}")                                                                                                     

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")                                                                                                                                
    set(MACOSX TRUE)                                                                                                                                                    
    include_directories(${CMAKE_SOURCE_DIR}/osx_inc/)                                                                                                                     
endif()                                                                                                                                                                   

set(Boost_USE_STATIC_LIBS ON)                                                                                                                                             
set(Boost_USE_MULTITHREADED ON)                                                                                                                                           
set(Boost_USE_STATIC_RUNTIME ON)                                                                                                                                          
find_package(Boost 1.75.0 COMPONENTS)                                                                                                                                     

if(Boost_FOUND)                                                                                                                                                           
    include_directories(${Boost_INCLUDE_DIRS})                                                                                                                            
    MESSAGE(STATUS "***boost found!*** ${Boost_INCLUDE_DIR}")                                                                                                             
endif()                                                                                                                                                                   

# add_executable(matching_engine MatchingEngine.cpp)
add_executable(order_book order_book_impl.cpp)
