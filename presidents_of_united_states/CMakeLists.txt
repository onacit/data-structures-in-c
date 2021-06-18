include_directories(include)

add_library(presidents_of_united_states include/presidents_of_united_states.h src/presidents_of_united_states.c)

add_executable(presidents_of_united_states_print1 include/presidents_of_united_states.h src/presidents_of_united_states.c apps/presidents_of_united_states_print1.c)
add_executable(presidents_of_united_states_print2 include/presidents_of_united_states.h src/presidents_of_united_states.c apps/presidents_of_united_states_print2.c)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/presidents_of_united_states.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})