if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(COMPILE_OPTIONS "/W3")
else()
    set(COMPILE_OPTIONS -Wall -Wextra -Weffc++)
endif()
if (DEFINED ENABLE_COVERAGE AND "${ENABLE_COVERAGE}" STREQUAL "yes")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        message(AUTHOR_WARNING "This template does not support coverage using MSVC")
    else()
        include(${PROJECT_SOURCE_DIR}/cmake/CodeCoverage.cmake)
        list(APPEND COMPILE_OPTIONS "--coverage")
        setup_target_for_coverage_gcovr_html(
            NAME template_tests_html_coverage
            DEPENDENCIES template_tests
            BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/src"
            EXCLUDE "${CMAKE_CURRENT_BINARY_DIR}/*" "${PROJECT_SOURCE_DIR}/tests/*"
        )
        message(STATUS "Coverage enabled")
    endif()
endif()

set(
    TESTS_SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/example_tests.cpp
)

add_executable(
    template_tests
        ${SRCS}
        ${INCLUDES}
        ${TESTS_SRCS}
)

target_link_libraries(
    template_tests
        Catch2::Catch2WithMain
)

target_include_directories(
    template_tests PRIVATE
        ../include
)

target_compile_options(
    template_tests PRIVATE
        ${COMPILE_OPTIONS}
)
