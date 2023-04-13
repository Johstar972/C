cmake_minimum_required(VERSION 3.23)
project(Interface)

set(CMAKE_CXX_STANDARD 14)

add_executable(Interface main.cpp)

target_link_libraries(Interface sfml-graphics sfml-window sfml-system)