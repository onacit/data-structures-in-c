include_directories(
        include
        ../list/include
)

link_libraries(
        list
)

add_library(
        array_list
        include/array_list.h
        src/array_list.c
)
#
#add_executable(
#        presidents_of_united_states_print1
#        include/singly_linked_node.h
#        src/singly_linked_node.c
#        include/singly_linked_list.h
#        src/singly_linked_list.c
#        apps/presidents_of_united_states_print1.c
#)
