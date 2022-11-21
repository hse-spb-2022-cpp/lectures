cmake_minimum_required(VERSION 3.22)

project(lectures-cmake CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)  # Should be before add_executable
add_executable(main src/main.cpp src/foo.cpp)
