#include <memory>


template<typename T> 
struct Node
{
    T value;
    std::unique_ptr<Node<T>> left = nullptr;
    std::unique_ptr<Node<T>> right = nullptr;
    Node* parent = nullptr;

    Node(T value) {
        this->value = value;
    }
};
