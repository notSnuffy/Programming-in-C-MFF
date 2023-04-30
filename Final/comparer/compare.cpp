#include "tree_comparer.h"
#include <AVL.h>
#include <BST.h>
#include <compared_BST.h>
#include <compared_AVL.h>
#include <iostream>

int main()
{
    // Binary Search Tree
    std::cout << "BINARY SEARCH TREE:" << std::endl;
    TreeComparer<BinarySearchTree<int>, BST, 10000> bst_comparer10000;
    bst_comparer10000.run();
    TreeComparer<BinarySearchTree<int>, BST, 100000> bst_comparer100000;
    bst_comparer100000.run();
    TreeComparer<BinarySearchTree<int>, BST, 1000000> bst_comparer1000000;
    bst_comparer1000000.run();

    // AVL Tree
    std::cout << "AVL TREE:" << std::endl;
    TreeComparer<AVLTree<int>, AVL<int>, 10000> avl_comparer10000;
    avl_comparer10000.run();
    TreeComparer<AVLTree<int>, AVL<int>, 100000> avl_comparer100000;
    avl_comparer100000.run();
    TreeComparer<AVLTree<int>, AVL<int>, 1000000> avl_comparer1000000;
    avl_comparer1000000.run();
    
    return 0;
}
