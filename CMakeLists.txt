cmake_minimum_required(VERSION 3.19)
project(data_structures_in_c C)

set(CMAKE_C_STANDARD 99)

add_library(data_structures_in_c singly_linked_list.c singly_linked_list.h singly_linked_node.h doubly_linked_node.h doubly_linked_list.h doubly_linked_list.c singly_linked_node.c doubly_linked_node.c common.h common.c)

enable_testing()

add_executable(singly_linked_node_test singly_linked_node_test.c)
add_test(NAME SinglyLinkedNodeTest COMMAND singly_linked_node_test)