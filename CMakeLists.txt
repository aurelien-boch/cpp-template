cmake_minimum_required(VERSION 3.11)
project(cpp-template)

add_subdirectory(src)
add_subdirectory(include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/packages")
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(COMPILE_FLAGS /W3)
else()
    set(COMPILE_FLAGS -Wall -Wextra -Weffc++)
endif()

if (DEFINED ENABLE_TESTING AND "${ENABLE_TESTING}" STREQUAL "yes")
    find_package(catch2)
    message(STATUS "ENABLE_TESTING=yes detected, enabling testing")
    add_subdirectory(tests)
endif()

add_executable(
    template
        main.cpp
        ${SRCS}
        ${INCLUDES}
)

target_include_directories(
    template PRIVATE
        include/
)

target_compile_options(
    template PRIVATE
        ${COMPILE_FLAGS}
)
