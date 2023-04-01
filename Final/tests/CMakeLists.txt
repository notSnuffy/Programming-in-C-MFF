
add_executable(tree_tests
    BST_test.cpp
    AVL_test.cpp
)


target_link_libraries(tree_tests 
gtest_main
SearchTrees)
target_include_directories(tree_tests PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Final/src"
                          )
gtest_discover_tests(tree_tests)
