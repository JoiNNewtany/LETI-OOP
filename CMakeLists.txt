cmake_minimum_required(VERSION 3.5)

project(Practice1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Practice1 main.cpp application.hpp application.cpp polynomial.hpp polynomial.cpp number.hpp)

install(TARGETS Practice1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
