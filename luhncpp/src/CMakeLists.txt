set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
 
add_executable(${BINARY} ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})