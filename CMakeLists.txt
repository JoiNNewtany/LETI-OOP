cmake_minimum_required(VERSION 3.5)

project(OOP_Practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
qt_standard_project_setup()

qt_add_executable(Practice4
    main.cpp
    polynomial.hpp
    complex.cpp complex.hpp
    mainwindow.cpp mainwindow.hpp mainwindow.ui
)

target_link_libraries(Practice4 PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

set_target_properties(Practice4 PROPERTIES
    WIN32_EXECUTABLE ON
)

install(TARGETS Practice4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
