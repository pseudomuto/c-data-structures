cmake_minimum_required(VERSION 3.10)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(cdatastructures LANGUAGES C CXX VERSION 0.1.0)
include(GNUInstallDirs)

################################################################################
# Compiler settings
################################################################################

option(CODE_COVERAGE "Enable coverage reporting" OFF)
if (CODE_COVERAGE AND CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    include(CodeCov)
endif ()

option(IWYU "Run include-what-you-use with the compiler" OFF)
if (IWYU)
    find_program(IWYU_COMMAND NAMES include-what-you-use iwyu)
    if (NOT IWYU_COMMAND)
        message(FATAL_ERROR "CMAKE_IWYU is ON but include-what-you-use is not found!")
    endif ()
    set(CMAKE_C_INCLUDE_WHAT_YOU_USE "${IWYU_COMMAND};-Xiwyu")
endif ()

################################################################################
# Dependencies
################################################################################
enable_testing()

################################################################################
# Main library
################################################################################
add_library(cdatastructures
        src/list.c
        src/map.c
        src/queue.c
        src/stack.c
        src/vector.c
        )

target_include_directories(cdatastructures
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

################################################################################
# Subdirectories
################################################################################
add_subdirectory(test)
