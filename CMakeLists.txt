cmake_minimum_required(VERSION 3.8)
project(SenseGlove-Robotics VERSION 1.0)

# Specify the C++ standard globally, if desired
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories here
add_subdirectory(examples/read_position)
add_subdirectory(examples/read_position_fingers)
add_subdirectory(examples/send_force)
