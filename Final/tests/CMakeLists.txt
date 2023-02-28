
add_executable(tree_tests
    BST_test.cpp
    AVL_test.cpp
)


target_link_libraries(tree_tests 
gtest_main
SearchTrees)
gtest_discover_tests(tree_tests)
