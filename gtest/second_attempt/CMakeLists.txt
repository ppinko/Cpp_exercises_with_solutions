cmake_minimum_required(VERSION 3.16)

set(This fdiv)

project(${This} C CXX)	

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
enable_testing()

add_subdirectory(googletest)

set(Headers
    fdiv.hpp
)

set(Sources 
    main.cpp
    fdiv.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
add_executable(main_exe ${Sources})
add_subdirectory(my_test)
