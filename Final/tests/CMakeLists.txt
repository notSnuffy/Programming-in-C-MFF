
add_executable(avl_tree_tests
AVL_test.cpp
)
add_executable(bst_tree_tests
BST_test.cpp
)

target_link_libraries(bst_tree_tests 
gtest_main
SearchTrees)
target_include_directories(bst_tree_tests PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Final/src"
                          )
gtest_discover_tests(bst_tree_tests)

target_link_libraries(avl_tree_tests 
gtest_main
SearchTrees)
target_include_directories(avl_tree_tests PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Final/src"
                          )
gtest_discover_tests(avl_tree_tests)
