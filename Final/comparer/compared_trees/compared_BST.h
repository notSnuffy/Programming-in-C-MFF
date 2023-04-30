/*
Code from:
https://github.com/pravahanj/Data_Structure-and-Algorithm-CodingNinjas.com/blob/main/BST/BST%20class.cpp
with slight modifications from me to make it work
1) search -> has_value
*/

using namespace std;
#include <iostream>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
    // Define the data members
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        // Implement the Constructor
        root = nullptr;
    }

    ~BST()
    {
        delete root;
    }

    /*----------------- Public Functions of BST -----------------*/
    // Remove function
private:
    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (data > node->data)
        {
            node->right = remove(data, node->right);
            return node;
        }
        else if (data < node->data)
        {
            node->left = remove(data, node->left);
            return node;
        }
        else
        {
            if (node->left == nullptr and node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = nullptr;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = remove(rightMin, node->right);
                return node;
            }
        }
    }

public:
    void remove(int data)
    {
        // Implement the remove() function
        root = remove(data, root);
    }

    // Print Function
private:
    void print(BinaryTreeNode<int> *root)
    {
        // Implement the print() function
        if (root == nullptr)
        {
            return;
        }

        cout << root->data << ":";

        if (root->left)
        {
            cout << "L:" << root->left->data << ",";
        }

        if (root->right)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        print(root->left);
        print(root->right);
    }

public:
    void print()
    {
        return print(root);
    }

    // Insert Function
private:
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if (data <= node->data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }

public:
    void insert(int data)
    {
        this->root = insert(data, this->root);
    }

    // Search Function
private:
    bool search(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->data == data)
        {
            return true;
        }
        else if (data < node->data)
        {
            return search(data, node->left);
        }
        else
        {
            return search(data, node->right);
        }
    }

public:
    bool has_value(int data)
    {
        // Implement the search() function
        return search(data, root);
    }
};
