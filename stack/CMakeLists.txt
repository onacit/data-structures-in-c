include_directories(
        include
        ../miscellaneous/include
        ../singly_linked_list/include
        ../list/include
)

link_libraries(
        miscellaneous
        singly_linked_list
        list
)

add_library(
        stack
        include/array_list_stack.h
        include/list_stack.h
        include/stack.h
        src/array_list_stack.c
        src/list_stack.c
        src/stack.c
        src/list_stack.c)
