cmake_minimum_required(VERSION 3.10)

project(shared-library CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)  # Recommended by Boost.DLL's manual

find_package(Boost 1.71 REQUIRED filesystem)  # Required by Boost.DLL
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# Windows: libmultiply.dll (msys2), multiply.dll (VS)
# Linux: libmultiply.so
# macOS: libmultiply.dylib
add_library(multiply SHARED plugin_multiply.cpp)
add_library(sum SHARED plugin_sum.cpp)

add_executable(main main.cpp)
target_link_libraries(main ${Boost_LIBRARIES} ${CMAKE_DL_LIBS})
