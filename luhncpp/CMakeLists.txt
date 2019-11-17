cmake_minimum_required(VERSION 2.8.9)
project(luhncpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(CMAKE_BUILD_TYPE Release)
 
include_directories(
  ${PROJECT_SOURCE_DIR}/include/
)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
add_executable(${PROJECT_NAME} ${SOURCES})
