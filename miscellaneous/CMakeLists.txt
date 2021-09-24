
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
        print_integer_limits
        apps/print_integer_limits.c
)

add_executable(
        print_presidents_of_united_states
        include/miscellaneous.h
        include/presidents_of_united_states.h
        src/miscellaneous.c
        src/presidents_of_united_states.c
        apps/print_presidents_of_united_states.c
)

# ------------------------------------------------------------------ miscellaneous_snprintf_ordinal_g_unsigned_char_test
add_executable(
        miscellaneous_snprintf_ordinal_g_unsigned_char_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_snprintf_ordinal_g_unsigned_char_test.c
)
add_test(
        NAME miscellaneous_snprintf_ordinal_g_unsigned_char_test
        COMMAND miscellaneous_snprintf_ordinal_g_unsigned_char_test 0 1 2 3 11 12 13 21 22 23 255
)

# ------------------------------------------------------------------- miscellaneous_snprintf_ordinal_g_unsigned_int_test
add_executable(
        miscellaneous_snprintf_ordinal_g_unsigned_int_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_snprintf_ordinal_g_unsigned_int_test.c
)
add_test(
        NAME miscellaneous_snprintf_ordinal_g_unsigned_int_test
        COMMAND miscellaneous_snprintf_ordinal_g_unsigned_int_test 0 1 2 3 11 12 13 21 22 23 65535
)

# -------------------------------------------------------------- miscellaneous_snprintf_ordinal_g_unsigned_long_int_test
add_executable(
        miscellaneous_snprintf_ordinal_g_unsigned_long_int_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_snprintf_ordinal_g_unsigned_long_int_test.c
)
add_test(
        NAME miscellaneous_snprintf_ordinal_g_unsigned_long_int_test
        COMMAND miscellaneous_snprintf_ordinal_g_unsigned_long_int_test 0 1 2 3 11 12 13 21 22 23 4294967295
)

# --------------------------------------------------------- miscellaneous_snprintf_ordinal_g_unsigned_long_long_int_test
add_executable(
        miscellaneous_snprintf_ordinal_g_unsigned_long_long_int_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_snprintf_ordinal_g_unsigned_long_long_int_test.c
)
add_test(
        NAME miscellaneous_snprintf_ordinal_g_unsigned_long_long_int_test
        COMMAND miscellaneous_snprintf_ordinal_g_unsigned_long_long_int_test 0 1 2 3 11 12 13 21 22 23 18446744073709551615
)

# ------------------------------------------------------------- miscellaneous_snprintf_ordinal_g_unsigned_short_int_test
add_executable(
        miscellaneous_snprintf_ordinal_g_unsigned_short_int_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_snprintf_ordinal_g_unsigned_short_int_test.c
)
add_test(
        NAME miscellaneous_snprintf_ordinal_g_unsigned_short_int_test
        COMMAND miscellaneous_snprintf_ordinal_g_unsigned_short_int_test 0 1 2 3 11 12 13 21 22 23 65535
)

# ---------------------------------------------------------------------------------- miscellaneous_snprintf_ordinal_test
add_executable(
        miscellaneous_snprintf_ordinal_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_snprintf_ordinal_test.cpp
)
target_link_libraries(
        miscellaneous_snprintf_ordinal_test
        gtest_main
)

# ------------------------------------------------------------------- miscellaneous_sprintf_ordinal_g_unsigned_char_test
add_executable(
        miscellaneous_sprintf_ordinal_g_unsigned_char_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_sprintf_ordinal_g_unsigned_char_test.c
)
add_test(
        NAME miscellaneous_sprintf_ordinal_g_unsigned_char_test
        COMMAND miscellaneous_sprintf_ordinal_g_unsigned_char_test 0 1 2 3 11 12 13 21 22 23 255
)

# -------------------------------------------------------------------- miscellaneous_sprintf_ordinal_g_unsigned_int_test
add_executable(
        miscellaneous_sprintf_ordinal_g_unsigned_int_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_sprintf_ordinal_g_unsigned_int_test.c
)
add_test(
        NAME miscellaneous_sprintf_ordinal_g_unsigned_int_test
        COMMAND miscellaneous_sprintf_ordinal_g_unsigned_int_test 0 1 2 3 11 12 13 21 22 23 65535
)

# --------------------------------------------------------------- miscellaneous_sprintf_ordinal_g_unsigned_long_int_test
add_executable(
        miscellaneous_sprintf_ordinal_g_unsigned_long_int_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_sprintf_ordinal_g_unsigned_long_int_test.c
)
add_test(
        NAME miscellaneous_sprintf_ordinal_g_unsigned_long_int_test
        COMMAND miscellaneous_sprintf_ordinal_g_unsigned_long_int_test 0 1 2 3 11 12 13 21 22 23 4294967295
)

# ---------------------------------------------------------- miscellaneous_sprintf_ordinal_g_unsigned_long_long_int_test
add_executable(
        miscellaneous_sprintf_ordinal_g_unsigned_long_long_int_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_sprintf_ordinal_g_unsigned_long_long_int_test.c
)
add_test(
        NAME miscellaneous_sprintf_ordinal_g_unsigned_long_long_int_test
        COMMAND miscellaneous_sprintf_ordinal_g_unsigned_long_long_int_test 0 1 2 3 11 12 13 21 22 23 18446744073709551615
)

# -------------------------------------------------------------- miscellaneous_sprintf_ordinal_g_unsigned_short_int_test
add_executable(
        miscellaneous_sprintf_ordinal_g_unsigned_short_int_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_sprintf_ordinal_g_unsigned_short_int_test.c
)
add_test(
        NAME miscellaneous_sprintf_ordinal_g_unsigned_short_int_test
        COMMAND miscellaneous_sprintf_ordinal_g_unsigned_short_int_test 0 1 2 3 11 12 13 21 22 23 65535
)

# ----------------------------------------------------------------------------------- miscellaneous_sprintf_ordinal_test
add_executable(
        miscellaneous_sprintf_ordinal_test
        include/miscellaneous.h
        src/miscellaneous.c
        test/miscellaneous_sprintf_ordinal_test.cpp
)
target_link_libraries(
        miscellaneous_sprintf_ordinal_test
        gtest_main
)

# ------------------------------------------------------------------------------------------------- gtest_discover_tests
gtest_discover_tests(
        miscellaneous_snprintf_ordinal_test
        miscellaneous_sprintf_ordinal_test
)
