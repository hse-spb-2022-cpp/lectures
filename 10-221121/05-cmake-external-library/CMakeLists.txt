cmake_minimum_required(VERSION 3.22)

project(lectures-cmake CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost 1.74 REQUIRED filesystem)
include_directories(${Boost_INCLUDE_DIRS})  # -I
link_directories(${Boost_LIBRARY_DIRS})  # -L

include_directories(include)  # Should be before add_executable
add_executable(main src/main.cpp src/foo.cpp)
target_link_libraries(main ${Boost_LIBRARIES})  # -l
