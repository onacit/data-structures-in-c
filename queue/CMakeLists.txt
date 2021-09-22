include_directories(
        include
        #        ../miscellaneous/include
        ../list/include
)

link_libraries(
        #        miscellaneous
        list
)

add_library(
        queue
        include/list_queue.h
        include/queue.h
        src/list_queue.c
        src/queue.c
        include/array_list_queue.h src/array_list_queue.c)
