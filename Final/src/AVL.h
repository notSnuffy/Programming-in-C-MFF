#ifndef AVL_H
#define AVL_H

#include <memory>
#include <optional>
#include <functional>


template <typename T, typename Comparator = std::less<T>>
class AVLTree
{
public:
    struct Node
    {
        T value;
        std::unique_ptr<Node> left = nullptr;
        std::unique_ptr<Node> right = nullptr;
        Node *parent = nullptr;
        int height = 1;

        Node(const T &value) : value(value) {}
    };

private:
    std::unique_ptr<Node> root;

    bool is_less_than(const T &a, const T &b, Comparator compare = Comparator{}) const
    {
        return compare(a, b);
    }

    bool is_equal(const T &a, const T &b) const
    {
        return !is_less_than(a, b) && !is_less_than(b, a);
    }

    Node *return_node_with_value(const T &value) const
    {
        Node *current = root.get();

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

    int height(const Node *node) const
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    void update_height(Node *node)
    {
        node->height = std::max(height(node->left.get()), height(node->right.get())) + 1;
    }

    std::unique_ptr<Node> left_rotate(std::unique_ptr<Node> node)
    {
        std::unique_ptr<Node> right_child = std::move(node->right);
        std::unique_ptr<Node> new_node = std::make_unique<Node>(node->value);
        new_node->right = std::move(right_child->left);
        if (new_node->right != nullptr)
        {
            new_node->right->parent = new_node.get();
        }
        new_node->parent = right_child.get();
        new_node->left = std::move(node->left);
        if (new_node->left != nullptr)
        {
            new_node->left->parent = new_node.get();
        }
        right_child->parent = node->parent;
        update_height(new_node.get());
        right_child->left = std::move(new_node);
        update_height(right_child.get());
        return right_child;
    }

    std::unique_ptr<Node> right_rotate(std::unique_ptr<Node> node)
    {
        std::unique_ptr<Node> left_child = std::move(node->left);
        std::unique_ptr<Node> new_node = std::make_unique<Node>(node->value);
        new_node->left = std::move(left_child->right);
        if (new_node->left != nullptr)
        {
            new_node->left->parent = new_node.get();
        }
        new_node->parent = left_child.get();
        new_node->right = std::move(node->right);
        if (new_node->right != nullptr)
        {
            new_node->right->parent = new_node.get();
        }

        left_child->parent = node->parent;
        update_height(new_node.get());
        left_child->right = std::move(new_node);
        update_height(left_child.get());
        return left_child;
    }

    int balance_factor(const Node *node) const
    {
        if (node == nullptr)
        {
            return 0;
        }
        return height(node->left.get()) - height(node->right.get());
    }

    std::unique_ptr<Node> rebalance(std::unique_ptr<Node> node)
    {
        update_height(node.get());

        int balance = balance_factor(node.get());

        // Left Left Case
        if (balance > 1 && balance_factor(node->left.get()) >= 0)
        {
            return std::unique_ptr<Node>(right_rotate(std::move(node)));
        }

        // Right Right Case
        if (balance < -1 && balance_factor(node->right.get()) <= 0)
        {
            return std::unique_ptr<Node>(left_rotate(std::move(node)));
        }

        // Left Right Case
        if (balance > 1 && balance_factor(node->left.get()) < 0)
        {
            node->left = left_rotate(std::move(node->left));
            return std::unique_ptr<Node>(right_rotate(std::move(node)));
        }

        // Right Left Case
        if (balance < -1 && balance_factor(node->right.get()) > 0)
        {
            node->right = std::unique_ptr<Node>(right_rotate(std::move(node->right)));
            return std::unique_ptr<Node>(left_rotate(std::move(node)));
        }

        return node;
    }

    std::optional<std::unique_ptr<Node>> _insert(std::unique_ptr<Node> node, const T &value)
    {
        // Leaf node
        if (node == nullptr)
        {
            return std::make_unique<Node>(value);
        }

        // Left child
        if (is_less_than(value, node->value))
        {
            std::unique_ptr<Node> new_node = _insert(std::move(node->left), value).value_or(nullptr);
            if (new_node == nullptr)
            {
                return {};
            }
            node->left = std::move(new_node);
            node->left->parent = node.get();
        }
        // Right child
        else if (is_less_than(node->value, value))
        {
            std::unique_ptr<Node> new_node = _insert(std::move(node->right), value).value_or(nullptr);
            if (new_node == nullptr)
            {
                return {};
            }
            node->right = std::move(new_node);
            node->right->parent = node.get();
        }
        // Duplicate
        else
        {
            return {};
        }

        return rebalance(std::move(node));
    }

    std::optional<std::unique_ptr<Node>> _remove(std::unique_ptr<Node> node, const T &value)
    {
        // No node
        if (node == nullptr)
        {
            return {};
        }

        // Left child
        if (is_less_than(value, node->value))
        {
            std::optional<std::unique_ptr<Node>> new_node = _remove(std::move(node->left), value);
            if (!new_node.has_value())
            {
                return {};
            }
            if (new_node.value() != nullptr)
            {
                new_node.value()->parent = node.get();
            }
            node->left = std::move(new_node.value());
        }
        // Right child
        else if (is_less_than(node->value, value))
        {
            std::optional<std::unique_ptr<Node>> new_node = _remove(std::move(node->right), value);
            if (!new_node.has_value())
            {
                return {};
            }
            if (new_node.value() != nullptr)
            {
                new_node.value()->parent = node.get();
            }
            node->right = std::move(new_node.value());
        }
        // Found node
        else
        {
            // No children
            if (node->left == nullptr && node->right == nullptr)
            {
                // Leaf node -> just remove
                return nullptr;
            }
            // Only right child
            else if (node->left == nullptr)
            {
                // Substitute node with right child
                return std::move(node->right);
            }
            // Only left child
            else if (node->right == nullptr)
            {
                // Substitute node with left child
                return std::move(node->left);
            }
            // Both children
            else
            {
                // Find successor
                Node *successor = node->right.get();
                while (successor->left != nullptr)
                {
                    successor = successor->left.get();
                }
                // Replace node with successor
                node->value = successor->value;
                // Remove successor
                std::optional<std::unique_ptr<Node>> new_node = _remove(std::move(node->right), successor->value);
                if (!new_node.has_value())
                {
                    return {};
                }
                if (new_node.value() != nullptr)
                {
                    new_node.value()->parent = node.get();
                }
                node->right = std::move(new_node.value());
            }
        }

        return rebalance(std::move(node));
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

        Iterator(Node *node) : current(node) {}

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
                Node *parent = current->parent;
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
                Node *parent = current->parent;
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
        Node *current = nullptr;
    };

    struct ReverseIterator : Iterator
    {
        ReverseIterator() = default;

        ReverseIterator(Node *node) : Iterator(node) {}

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
        Node *current = root.get();

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
        Node *current = return_node_with_value(value);

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
        Node *current = return_node_with_value(value);

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
        Node *current = return_node_with_value(value);

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
        Node *current = return_node_with_value(value);

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
        Node *current = return_node_with_value(value);

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
        Node *current = return_node_with_value(value);

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
        Node *parent = current->parent;
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
        Node *current = return_node_with_value(value);

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
        Node *parent = current->parent;
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
        Node *current = root.get();
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
        Node *current = root.get();
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
        Node *current = return_node_with_value(value);
        if (current == nullptr)
        {
            return Iterator();
        }

        return Iterator(current);
    }

    bool insert(const T &value)
    {
        std::unique_ptr<Node> new_root = _insert(std::move(root), value).value_or(nullptr);
        if (new_root == nullptr)
        {
            return false;
        }
        root = std::move(new_root);
        return true;
    }

    bool remove(const T &value)
    {
        /*
            This check is important for the reason that I move the root to the _remove function meaning if the node does not exist
            the whole tree becomes empty since I can not access the old root values -> probably should pass raw pointers
        */
        if (return_node_with_value(value) == nullptr)
        {
            return false;
        }
        std::optional<std::unique_ptr<Node>> new_root = _remove(std::move(root), value);
        if (!new_root.has_value())
        {
            return false;
        }
        root = std::move(new_root.value());
        return true;
    }
};

#endif // AVL_H
