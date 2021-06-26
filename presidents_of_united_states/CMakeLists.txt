include_directories(include ../miscellaneous/include)

link_libraries(miscellaneous)

add_library(presidents_of_united_states
        include/presidents_of_united_states.h src/presidents_of_united_states.c
        include/presidents_of_united_states_misc.h src/presidents_of_united_states_misc.c)

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
        include/presidents_of_united_states_misc.h
        src/presidents_of_united_states.c
        src/presidents_of_united_states_misc.c
        apps/presidents_of_united_states_list_up.c)
#target_link_libraries(presidents_of_united_states_list_up miscellaneous)

add_executable(presidents_of_united_states_print_current
        include/presidents_of_united_states.h
        include/presidents_of_united_states_misc.h
        src/presidents_of_united_states.c
        src/presidents_of_united_states_misc.c
        apps/presidents_of_united_states_print_current.c)
#target_link_libraries(presidents_of_united_states_print_current miscellaneous)

add_executable(presidents_of_united_states_print_first
        include/presidents_of_united_states.h
        include/presidents_of_united_states_misc.h
        src/presidents_of_united_states.c
        src/presidents_of_united_states_misc.c
        apps/presidents_of_united_states_print_first.c)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/presidents_of_united_states.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
#        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)