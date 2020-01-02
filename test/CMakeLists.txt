include(CMocka)

include_directories(${CMOCKA_INCLUDE_DIR})

function(add_test_suite _testName)
    add_executable(${_testName} src/${_testName}.c)
    target_link_libraries(${_testName} cdatastructures cmocka)
    add_test(${_testName} ${CMAKE_CURRENT_BINARY_DIR}/${_testName})
endfunction()

add_test_suite(list_tests)
add_test_suite(map_tests)
add_test_suite(queue_tests)
add_test_suite(stack_tests)
add_test_suite(vector_tests)
