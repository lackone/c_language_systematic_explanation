#include <stdio.h>

/*
动态链接库
cmake_minimum_required(VERSION 3.29)
project(sum C)

set(CMAKE_C_STANDARD 11)

if (WIN32)
   set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif (WIN32)

add_library(sum SHARED sum.c)

install(TARGETS sum
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
 */

/*
静态链接库
cmake_minimum_required(VERSION 3.29)
project(sum C)

set(CMAKE_C_STANDARD 11)

add_library(sum STATIC sum.c)
 */
int main(void) {
    return 0;
}
