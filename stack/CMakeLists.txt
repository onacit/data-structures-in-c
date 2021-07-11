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

add_library(stack include/stack.h src/stack.c)
