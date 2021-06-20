include_directories(include)

add_library(presidents_of_united_states include/presidents_of_united_states.h src/presidents_of_united_states.c)

add_executable(presidents_of_united_states_find_by_presidency
        include/presidents_of_united_states.h
        src/presidents_of_united_states.c
        apps/presidents_of_united_states_find_by_presidency.c)
add_executable(presidents_of_united_states_find_by_president
        include/presidents_of_united_states.h
        src/presidents_of_united_states.c
        apps/presidents_of_united_states_find_by_president.c)
add_executable(presidents_of_united_states_list_up
        include/presidents_of_united_states.h
        src/presidents_of_united_states.c
        apps/presidents_of_united_states_list_up.c)
add_executable(presidents_of_united_states_print_first
        include/presidents_of_united_states.h
        src/presidents_of_united_states.c
        apps/presidents_of_united_states_print_first.c)
add_executable(presidents_of_united_states_print_latest
        include/presidents_of_united_states.h
        src/presidents_of_united_states.c
        apps/presidents_of_united_states_print_latest.c)

file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/src/presidents_of_united_states.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})