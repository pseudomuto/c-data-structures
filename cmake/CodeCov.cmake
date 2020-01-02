# Prerequisites
find_program(GCOVR_PATH gcovr PATHS ${CMAKE_SOURCE_DIR}/scripts/test)

set(CMAKE_C_FLAGS_CODECOV "-O0 -g --coverage" CACHE INTERNAL "")
mark_as_advanced(CMAKE_C_FLAGS_CODECOV)

# Ensure we're using a debug build
string(TOLOWER ${CMAKE_BUILD_TYPE} current_build_type)
if (NOT current_build_type STREQUAL "debug")
    message(WARNING "Code coverage results with an optimised (non-Debug) build may be misleading")
endif ()

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    link_libraries(gcov)
endif ()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_CODECOV}")
message(STATUS "Appending code coverage compiler flags: ${CMAKE_C_FLAGS_CODECOV}")

add_custom_target(codecov
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
        COMMENT "Generating code cov report at ${PROJECT_BINARY_DIR}/codecov.xml"
        COMMAND ${GCOVR_PATH} --exclude-throw-branches -r .. --object-directory "${PROJECT_BINARY_DIR}" -e ".*/test/.*" -e ".*/usr/.*" --print-summary
        COMMAND ${GCOVR_PATH} --xml --exclude-throw-branches -r .. --object-directory "${PROJECT_BINARY_DIR}" -e ".*/test/.*" -e ".*/usr/.*" -o codecov.xml)
