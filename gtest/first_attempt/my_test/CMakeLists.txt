cmake_minimum_required(VERSION 3.16)

set(This FdivTests)

set(Sources
    FdivTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    fdiv
)
add_test(
    NAME ${This}
    COMMAND ${This}
)