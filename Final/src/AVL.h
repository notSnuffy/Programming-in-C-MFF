#include "Node.h"
#include <memory>

template <typename T>
struct AVLNode : Node<T>
{
    AVLNode(T value) : Node<T>(value) {}
    int height = 1;
};

template <typename T, typename Comparator = std::less<T>>
class AVLTree
{
private:
    std::unique_ptr<AVLNode<T>> root;

    bool is_less_than(const T &a, const T &b, Comparator compare = Comparator{}) const
    {
        return compare(a, b);
    }

    bool is_equal(const T &a, const T &b) const
    {
        return !is_less_than(a, b) && !is_less_than(b, a);
    }

    AVLNode<T> *return_node_with_value(const T &value) const
    {
        AVLNode<T> *current = root.get();

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

    int height(const AVLNode<T> *node) const
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    void update_height(AVLNode<T> *node)
    {
        node->height = std::max(height(node->left.get()), height(node->right.get())) + 1;
    }

    std::unique_ptr<AVLNode<T>> left_rotate(AVLNode<T> *node)
    {
        std::unique_ptr<AVLNode<T>> right_child = std::move(node->right);
        node->right = std::move(right_child->left);
        node->parent = right_child.get();

        right_child->parent = node->parent;
        right_child->left = std::move(node);
        update_height(node);
        update_height(right_child);
        return right_child;
    }

    std::unique_ptr<AVLNode<T>> right_rotate(AVLNode<T> *node)
    {
        std::unique_ptr<AVLNode<T>> left_child = std::move(node->left);
        node->left = std::move(left_child->right);
        node->parent = left_child.get();

        left_child->parent = node->parent;
        left_child->right = std::move(node);
        update_height(node);
        update_height(left_child);
        return left_child;
    }

public:
    struct Iterator
    {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        // we return only value not node and const so it doesn't break the tree invariant
        using value_type = T;
        using reference = const T &;
        using pointer = const T *;
        using difference_type = std::ptrdiff_t;

        Iterator() = default;

        Iterator(AVLNode<T> *node) : current(node) {}

        bool operator==(const Iterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }

        reference operator*() const
        {
            return current->value;
        }

        pointer operator->() const
        {
            return &current->value;
        }

        virtual Iterator &operator++()
        {
            // No node
            if (current == nullptr)
            {
                return *this;
            }

            // Get minimum of right subtree
            if (current->right != nullptr)
            {
                current = current->right.get();
                while (current->left != nullptr)
                {
                    current = current->left.get();
                }
            }
            // Successor is supposed to be parent of the closest ancestor that is left child
            else
            {
                AVLNode<T> *parent = current->parent;
                while (parent != nullptr && current == parent->right.get())
                {
                    current = parent;
                    parent = parent->parent;
                }
                current = parent;
            }
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator copy = *this;
            ++(*this);
            return copy;
        }

        virtual Iterator &operator--()
        {
            if (current == nullptr)
            {
                return *this;
            }

            // Get maximum of left subtree
            if (current->left != nullptr)
            {
                current = current->left.get();
                while (current->right != nullptr)
                {
                    current = current->right.get();
                }
            }
            // Successor is supposed to be parent of the closest ancestor that is right child
            else
            {
                AVLNode<T> *parent = current->parent;
                while (parent != nullptr && current == parent->left.get())
                {
                    current = parent;
                    parent = parent->parent;
                }
                current = parent;
            }
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator copy = *this;
            --(*this);
            return copy;
        }

    private:
        AVLNode<T> *current = nullptr;
    };

    struct ReverseIterator : Iterator
    {
        ReverseIterator() = default;

        ReverseIterator(AVLNode<T> *node) : Iterator(node) {}

        ReverseIterator &operator++()
        {
            Iterator::operator--();
            return *this;
        }

        ReverseIterator &operator--()
        {
            Iterator::operator++();
            return *this;
        }
    };

    bool has_value(const T &value) const
    {
        AVLNode<T> *current = root.get();

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
        AVLNode<T> *current = return_node_with_value(value);

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
        AVLNode<T> *current = return_node_with_value(value);

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
        AVLNode<T> *current = return_node_with_value(value);

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
        AVLNode<T> *current = return_node_with_value(value);

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
        AVLNode<T> *current = return_node_with_value(value);

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
        AVLNode<T> *current = return_node_with_value(value);

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
        AVLNode<T> *parent = current->parent;
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
        AVLNode<T> *current = return_node_with_value(value);

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
        AVLNode<T> *parent = current->parent;
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

    Iterator begin() const
    {
        AVLNode<T> *current = root.get();
        if (current == nullptr)
        {
            return Iterator();
        }

        current = return_node_with_value(minimum().value());
        return Iterator(current);
    }

    Iterator end() const
    {
        return Iterator();
    }

    ReverseIterator rbegin() const
    {
        AVLNode<T> *current = root.get();
        if (current == nullptr)
        {
            return ReverseIterator();
        }

        current = return_node_with_value(maximum().value());
        return ReverseIterator(current);
    }

    ReverseIterator rend() const
    {
        return ReverseIterator();
    }

    Iterator find(const T &value) const
    {
        AVLNode<T> *current = return_node_with_value(value);
        if (current == nullptr)
        {
            return Iterator();
        }

        return Iterator(current);
    }

};
