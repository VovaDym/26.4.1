# CMakeList.txt : CMake project for 26.4.1.player, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("26.4.1.player")

set (CMAKE_CXX_STANDARD 14)
# Add source to this project's executable.
set ( MY_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

# TODO: Add tests and install targets if needed.
add_subdirectory (src)