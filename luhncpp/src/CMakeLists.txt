set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES luhn.cpp main.cpp)
 
add_executable(${BINARY} ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})