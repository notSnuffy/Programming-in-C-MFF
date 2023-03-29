#include "Node.h"
#include <memory>
#include <functional>
#include <optional>

template <typename T, typename Comparator = std::less<T>>
class BinarySearchTree
{
private:
    std::unique_ptr<Node<T>> root;

    bool is_less_than(const T &a, const T &b, Comparator compare = Comparator{}) const
    {
        return compare(a, b);
    }

    Node<T> *return_node_with_value(const T &value) const
    {
        Node<T> *current = root.get();

        while (current != nullptr)
        {
            if (is_less_than(value, current->value))
            {
                current = current->left.get();
            }
            else if (is_less_than(current->value, value))
            {
                current = current->right.get();
            }
            else
            {
                return current;
            }
        }

        return nullptr;
    }

public:
    bool has_value(const T &value) const
    {
        Node<T> *current = root.get();

        while (current != nullptr)
        {
            if (is_less_than(value, current->value))
            {
                current = current->left.get();
            }
            else if (is_less_than(current->value, value))
            {
                current = current->right.get();
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    std::optional<T> maximum(const T &value) const
    {
        Node<T> *current = return_node_with_value(value);

        // No node with value
        if (current == nullptr)
        {
            return {};
        }

        // Go all the way to the right
        while (current->right != nullptr)
        {
            current = current->right.get();
        }
        return current->value;
    }

    std::optional<T> maximum() const
    {
        // Empty tree
        if (root == nullptr)
        {
            return {};
        }

        return maximum(root->value);
    }

    std::optional<T> minimum() const
    {
        Node<T> *current = root.get();

        // Empty tree
        if (current == nullptr)
        {
            return {};
        }

        // Go all the way to the left
        while (current->left != nullptr)
        {
            current = current->left.get();
        }
        return current->value;
    }

    std::optional<T> successor(const T &value) const
    {
        Node<T> *current = root.get();

        // Empty tree
        if (current == nullptr)
        {
            return {};
        }

        while (current != nullptr)
        {
            if (is_less_than(value, current->value))
            {
                current = current->left.get();
            }
            else if (is_less_than(current->value, value))
            {
                current = current->right.get();
            }
            else
            {
                break;
            }
        }
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
