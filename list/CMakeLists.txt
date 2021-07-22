include_directories(
        ../miscellaneous/include
        include
)

add_library(
        list
        include/array_list.h
        include/list.h
        include/singly_linked_list.h
        include/singly_linked_node.h
        src/array_list.c
        src/list.c
        src/singly_linked_list.c
        src/singly_linked_node.c
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

add_executable(
        array_list_insert_first_delete_first
        include/array_list.h
        include/list.h
        src/array_list.c
        src/list.c
        apps/array_list_insert_first_delete_first.c
)

add_executable(
        array_list_insert_first_delete_last
        include/array_list.h
        include/list.h
        src/array_list.c
        src/list.c
        apps/array_list_insert_first_delete_last.c
)

add_executable(
        array_list_insert_last_delete_first
        include/array_list.h
        include/list.h
        src/array_list.c
        src/list.c
        apps/array_list_insert_last_delete_first.c
)

add_executable(
        array_list_insert_last_delete_last
        include/array_list.h
        include/list.h
        src/array_list.c
        src/list.c
        apps/array_list_insert_last_delete_last.c
)
