#include "AVL.h"

int main(int argc, char const *argv[])
{

    AVLTree<int> tree;
    tree.insert(3);
    tree.insert(8);
    tree.insert(10);
    tree.insert(14);
    tree.insert(13);
    tree.insert(13);
    tree.insert(1);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    return 0;
}
