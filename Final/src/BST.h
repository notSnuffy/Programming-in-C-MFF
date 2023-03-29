#include "Node.h"
#include <memory>
#include <functional>

template <typename T, typename Comparator = std::less<T>>
class BinarySearchTree
{
private:
    std::unique_ptr<Node<T>> root;

    bool is_less_than(const T &a, const T &b, Comparator compare = Comparator{}) const
    {
        return compare(a, b);
    }

public:
    bool has_value(const T &value) const
    {
        Node<T>* current = root.get();

        while(current != nullptr) {
            if(is_less_than(value, current->value)) {
                current = current->left.get();
            } else if(is_less_than(current->value, value)) {
                current = current->right.get();
            } else {
                return true;
            }
        }

        return false;
    }

    bool insert(const T &value)
    {
        // Insert to root
        if (root == nullptr)
        {
            root = std::make_unique<Node<T>>(value);
            return true;
        }

        Node<T> *current = root.get();
        Node<T> *parent = nullptr;

        while (current != nullptr)
        {
            parent = current;
            if (is_less_than(value, current->value))
            {
                current = current->left.get();
            }
            else if (is_less_than(current->value, value))
            {
                current = current->right.get();
            }
            // Do not insert -> duplicate value
            else
            {
                return false;
            }
        }

        // We have current as leaf node -> we insert somewhere to parent node
        // Here we figure out where
        if (is_less_than(value, parent->value))
        {
            parent->left = std::make_unique<Node<T>>(value);
            parent->left->parent = parent;
        }
        else
        {
            parent->right = std::make_unique<Node<T>>(value);
            parent->right->parent = parent;
        }

        return true;
    }
};
