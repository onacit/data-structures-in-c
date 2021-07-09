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

add_executable(
        a
        apps/a.c
)
