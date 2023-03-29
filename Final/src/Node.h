#include <memory>


template<typename T> 
struct Node
{
    T value;
    std::unique_ptr<Node<T>> left;
    std::unique_ptr<Node<T>> right;
    Node* parent;

    Node(T value) {
        this->value = value;
    }
};
