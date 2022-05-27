# CMakeList.txt : CMake project for 26.4.1.player, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)



# Add source to this project's executable.
add_executable (26.4.1.player "main.cpp")

target_include_directories (26.4.1.player PUBLIC ${MY_INCLUDE_PATH})

# TODO: Add tests and install targets if needed.
