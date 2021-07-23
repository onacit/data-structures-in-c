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
        presidents_of_united_states_find_by_presidency
        include/presidents_of_united_states.h
        src/presidents_of_united_states.c
        apps/presidents_of_united_states_find_by_presidency.c
)

add_executable(
        presidents_of_united_states_find_by_president
        include/presidents_of_united_states.h
        src/presidents_of_united_states.c
        apps/presidents_of_united_states_find_by_president.c
)

add_executable(
        presidents_of_united_states_list_up
        include/miscellaneous.h
        include/presidents_of_united_states.h
        src/miscellaneous.c
        src/presidents_of_united_states.c
        apps/presidents_of_united_states_list_up.c
)

add_executable(
        presidents_of_united_states_print_current
        include/miscellaneous.h
        include/presidents_of_united_states.h
        src/miscellaneous.c
        src/presidents_of_united_states.c
        apps/presidents_of_united_states_print_current.c
)

add_executable(
        presidents_of_united_states_print_first
        include/miscellaneous.h
        include/presidents_of_united_states.h
        src/miscellaneous.c
        src/presidents_of_united_states.c
        apps/presidents_of_united_states_print_first.c
)
