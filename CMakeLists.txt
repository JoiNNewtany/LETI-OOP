cmake_minimum_required(VERSION 3.5)

project(OOP_Practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Practice2 main.cpp application.hpp application.cpp polynomial.hpp polynomial.cpp number.hpp complex.hpp complex.cpp)

install(TARGETS Practice2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
