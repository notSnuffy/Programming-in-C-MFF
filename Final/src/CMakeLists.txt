add_library(SearchTrees INTERFACE BST.h AVL.h)
add_executable(SearchTreeMain main.cpp Node.h BST.h)
target_include_directories(SearchTrees INTERFACE BST.h AVL.h)
