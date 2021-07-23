include_directories(
        include
#        ../miscellaneous/include
#        ../list/include
)

link_libraries(
#        miscellaneous
        list
)

add_library(
        queue
        include/queue.h
        src/queue.c
)
