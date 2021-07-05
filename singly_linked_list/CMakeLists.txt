include_directories(
        include
        ../miscellaneous/include
        ../presidents_of_united_states/include
)

link_libraries(
        miscellaneous
        presidents_of_united_states
)

add_library(
        singly_linked_list
        include/singly_linked_node.h
        src/singly_linked_node.c
        include/singly_linked_list.h
        src/singly_linked_list.c
)

add_executable(
        presidents_of_united_states_print1
        include/singly_linked_node.h
        src/singly_linked_node.c
        include/singly_linked_list.h
        src/singly_linked_list.c
        apps/presidents_of_united_states_print1.c
)
