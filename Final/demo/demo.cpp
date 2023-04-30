#include <AVL.h>
#include <BST.h>
#include <vector>
#include <iostream>

template <template <typename> class Tree>
bool subsequence_exists(const Tree<int> &tree, std::vector<int> &sequence)
{
    if (sequence.empty())
    {
        return true;
    }
    sort(sequence.begin(), sequence.end());

    int index = 0;
    for (auto it = tree.begin(); it != tree.end(); ++it)
    {
        if (*it == sequence[index])
        {
            ++index;
            if (index == sequence.size())
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    // Build Binary Search Tree
    BinarySearchTree<int> bst;
    bst.insert(8);
    bst.insert(10);
    bst.insert(3);
    bst.insert(6);
    bst.insert(1);
    bst.insert(4);
    bst.insert(7);
    bst.insert(14);
    bst.insert(13);

    // Build AVL Tree
    AVLTree<int> avl;
    avl.insert(8);
    avl.insert(10);
    avl.insert(3);
    avl.insert(6);
    avl.insert(1);
    avl.insert(4);
    avl.insert(7);
    avl.insert(14);
    avl.insert(13);
    avl.insert(15);
    avl.remove(6);

    // -------------------------------------------------------------------------------------------------------------------
    // BOTH FALSE
    std::cout << "BOTH FALSE" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    // Test if BST contains a subsequence
    std::vector<int> sequence1 = {8, 3, 15, 4, 20};
    std::cout << "BST contains subsequence: " << (subsequence_exists<BinarySearchTree>(bst, sequence1) ? "true" : "false") << std::endl;

    // Test if AVL contains a subsequence
    std::cout << "AVL contains subsequence: " << (subsequence_exists<AVLTree>(avl, sequence1) ? "true" : "false") << std::endl;

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    // -------------------------------------------------------------------------------------------------------------------
    // BST TRUE, AVL FALSE
    std::cout << "BST TRUE, AVL FALSE" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    // Test if BST contains a subsequence
    std::vector<int> sequence2 = {8, 3, 14, 4, 6};
    std::cout << "BST contains subsequence: " << (subsequence_exists<BinarySearchTree>(bst, sequence2) ? "true" : "false") << std::endl;

    // Test if AVL contains a subsequence
    std::cout << "AVL contains subsequence: " << (subsequence_exists<AVLTree>(avl, sequence2) ? "true" : "false") << std::endl;

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    // -------------------------------------------------------------------------------------------------------------------
    // BST FALSE, AVL TRUE
    std::cout << "BST FALSE, AVL TRUE" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    // Test if BST contains a subsequence
    std::vector<int> sequence3 = {8, 3, 14, 4, 15};
    std::cout << "BST contains subsequence: " << (subsequence_exists<BinarySearchTree>(bst, sequence3) ? "true" : "false") << std::endl;

    // Test if AVL contains a subsequence
    std::cout << "AVL contains subsequence: " << (subsequence_exists<AVLTree>(avl, sequence3) ? "true" : "false") << std::endl;

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    // -------------------------------------------------------------------------------------------------------------------
    // BOTH TRUE
    std::cout << "BOTH TRUE" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    // Test if BST contains a subsequence
    std::vector<int> sequence4 = {8, 3, 14, 4, 7};
    std::cout << "BST contains subsequence: " << (subsequence_exists<BinarySearchTree>(bst, sequence4) ? "true" : "false") << std::endl;

    // Test if AVL contains a subsequence
    std::cout << "AVL contains subsequence: " << (subsequence_exists<AVLTree>(avl, sequence4) ? "true" : "false") << std::endl;

    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    return 0;
}
