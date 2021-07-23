#cmake_minimum_required(VERSION 3.19)
cmake_minimum_required(VERSION 3.16)
project(data_structures_in_c C)

set(CMAKE_C_STANDARD 99)

add_library(data_structures_in_c common.h common.c)

enable_testing()

#add_executable(singly_linked_node_test singly_linked_node_test.c)


#add_test(NAME SinglyLinkedNodeTest COMMAND singly_linked_node_test)

add_subdirectory(miscellaneous)
#add_subdirectory(presidents_of_united_states)
add_subdirectory(list)
add_subdirectory(stack)
add_subdirectory(queue)