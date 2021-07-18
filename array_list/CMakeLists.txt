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
        array_list_insert_first_delete_first
        include/array_list.h
        src/array_list.c
        apps/array_list_insert_first_delete_last.c
)

add_executable(
        array_list_insert_first_delete_last
        include/array_list.h
        src/array_list.c
        apps/array_list_insert_first_delete_last.c
)

add_executable(
        array_list_insert_last_delete_first
        include/array_list.h
        src/array_list.c
        apps/array_list_insert_last_delete_first.c
)

add_executable(
        array_list_insert_last_delete_last
        include/array_list.h
        src/array_list.c
        apps/array_list_insert_last_delete_last.c
)
