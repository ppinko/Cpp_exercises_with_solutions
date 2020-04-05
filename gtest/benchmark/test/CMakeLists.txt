cmake_minimum_required(VERSION 3.16)

set(This ExampleTests)

set(Sources
    ExampleTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    gtest_guide
)

add_test(
    NAME ${This}
    COMMAND ${This}
)