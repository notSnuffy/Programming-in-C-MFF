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

    bool is_equal(const T &a, const T &b) const
    {
        return !is_less_than(a, b) && !is_less_than(b, a);
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

    std::optional<T> left_child_value(const T &value) const
    {
        Node<T> *current = return_node_with_value(value);

        // No node with value
        if (current == nullptr)
        {
            return {};
        }

        // No left child
        if (current->left == nullptr)
        {
            return {};
        }

        return current->left->value;
    }

    std::optional<T> right_child_value(const T &value) const
    {
        Node<T> *current = return_node_with_value(value);

        // No node with value
        if (current == nullptr)
        {
            return {};
        }

        // No right child
        if (current->right == nullptr)
        {
            return {};
        }

        return current->right->value;
    }

    std::optional<T> parent_value(const T &value) const
    {
        Node<T> *current = return_node_with_value(value);

        // No node with value
        if (current == nullptr)
        {
            return {};
        }

        // No parent
        if (current->parent == nullptr)
        {
            return {};
        }

        return current->parent->value;
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

    std::optional<T> minimum(const T &value) const
    {
        Node<T> *current = return_node_with_value(value);

        // No node with value
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

    std::optional<T> minimum() const
    {
        // Empty tree
        if (root == nullptr)
        {
            return {};
        }

        return minimum(root->value);
    }

    std::optional<T> successor(const T &value) const
    {
        Node<T> *current = return_node_with_value(value);

        // No node
        if (current == nullptr)
        {
            return {};
        }

        // If right child exists -> successor is minimum from that child
        if (current->right != nullptr)
        {
            return minimum(current->right->value).value();
        }

        // Successor is supposed to be parent of the closest ancestor that is left child
        Node<T> *parent = current->parent;
        while (parent != nullptr && parent->right != nullptr && is_equal(current->value, parent->right->value))
        {
            current = parent;
            parent = parent->parent;
        }

        // No successor
        if (parent == nullptr)
        {
            return {};
        }

        return parent->value;
    }

    std::optional<T> predecessor(const T &value) const
    {
        Node<T> *current = return_node_with_value(value);

        // No node
        if (current == nullptr)
        {
            return {};
        }

        // If left child exists -> predecessor is maximum from that child
        if (current->left != nullptr)
        {
            return maximum(current->left->value).value();
        }

        // Predecessor is supposed to be parent of the closest ancestor that is right child
        Node<T> *parent = current->parent;
        while (parent != nullptr && parent->left != nullptr && is_equal(current->value, parent->left->value))
        {
            current = parent;
            parent = parent->parent;
        }

        // No predecessor
        if (parent == nullptr)
        {
            return {};
        }

        return parent->value;
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

    bool remove(const T &value)
    {
        Node<T> *current = return_node_with_value(value);

        // No node
        if (current == nullptr)
        {
            return false;
        }

        // No children
        if (current->left == nullptr && current->right == nullptr)
        {
            // Deleted node is root
            if (current == root.get())
            {
                root = nullptr;
            }
            // Deleted node is a left child
            else if (current == current->parent->left.get())
            {
                current->parent->left = nullptr;
            }
            // Deleted node is a right child
            else
            {
                current->parent->right = nullptr;
            }
        }
        // One child
        else if (current->left == nullptr || current->right == nullptr)
        {
            // Get child of deleted node
            std::unique_ptr<Node<T>> child = current->left == nullptr ? std::move(current->right) : std::move(current->left);

            // Deleted node is the root
            if (current == root.get())
            {
                root = std::move(child);
                root->parent = nullptr;
            }
            // Deleted node is a left child
            else if (current == current->parent->left.get())
            {
                child->parent = current->parent;
                current->parent->left = std::move(child);
            }
            // Deleted node is a right child
            else
            {
                child->parent = current->parent;
                current->parent->right = std::move(child);
            }
        }

        return true;
    }
};
