cmake_minimum_required(VERSION 2.8.9)
project(luhncpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)
 
include_directories(
  ${PROJECT_SOURCE_DIR}/include/
)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
