cmake_minimum_required(VERSION 3.17)
project(labs-assignments)

set(CMAKE_CXX_STANDARD 20)


include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
        )
        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
        include(GoogleTest)
        
enable_testing()
add_subdirectory(labs)
add_subdirectory(Final)

# add warnings as errors
target_compile_options(avl_tree_tests PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_compile_options(bst_tree_tests PRIVATE -Wall -Wextra -Wpedantic -Werror)
