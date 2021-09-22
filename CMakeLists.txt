#cmake_minimum_required(VERSION 3.19)
cmake_minimum_required(VERSION 3.16)
#cmake_minimum_required(VERSION 3.14)
project(data_structures_in_c)

set(CMAKE_CXX_STANDARD 11)

#add_library(data_structures_in_c)

#add_executable(singly_linked_node_test singly_linked_node_test.c)


#add_test(NAME SinglyLinkedNodeTest COMMAND singly_linked_node_test)

add_subdirectory(miscellaneous)
#add_subdirectory(presidents_of_united_states)
add_subdirectory(list)
add_subdirectory(stack)
add_subdirectory(queue)

# ---------------------------------------------------------------------------------------------------------- Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)
