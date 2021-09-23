
include_directories(
        include
)

file(
        COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/src/presidents_of_united_states.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_library(
        miscellaneous
        include/miscellaneous.h
        include/presidents_of_united_states.h
        src/miscellaneous.c
        src/presidents_of_united_states.c
)

add_executable(
        print_presidents_of_united_states
        include/miscellaneous.h
        include/presidents_of_united_states.h
        src/miscellaneous.c
        src/presidents_of_united_states.c
        apps/print_presidents_of_united_states.c
)

enable_testing()
include(GoogleTest)

add_executable(
        miscellaneous_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_test.cpp
)

target_link_libraries(
        miscellaneous_test
        gtest_main
)

gtest_discover_tests(miscellaneous_test)
