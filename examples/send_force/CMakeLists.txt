cmake_minimum_required(VERSION 3.8)
project(send_force)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# SGCoreCpp library paths
set(SGCORE_CPP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../external/Core/SGCoreCpp")

# SGConnect library paths
set(SGCONNECT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../external/Core/SGConnect")

message(STATUS "SGCORE_CPP_PATH: ${SGCORE_CPP_PATH}")
message(STATUS "SGCONNECT_PATH: ${SGCONNECT_PATH}")

# Include directories for SGCoreCpp and SGConnect headers
include_directories(
    "${SGCORE_CPP_PATH}/incl"
    "${SGCONNECT_PATH}/incl"
)

# Define the executable
add_executable(${PROJECT_NAME} send_force.cpp)

# Link the SGCoreCpp and SGConnect libraries using full paths
target_link_libraries(${PROJECT_NAME}
    "${SGCORE_CPP_PATH}/lib/linux/Debug/libSGCoreCpp.so"
    "${SGCONNECT_PATH}/lib/linux/Debug/libSGConnect.so"
)
