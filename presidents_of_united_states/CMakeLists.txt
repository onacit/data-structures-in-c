include_directories(include)

add_library(presidents_of_united_states include/presidents_of_united_states.h src/presidents_of_united_states.c)

add_executable(presidents_of_united_states_print include/presidents_of_united_states.h src/presidents_of_united_states.c apps/presidents_of_united_states_print.c)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/presidents_of_united_states.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})