#include "Node.h"
#include <memory>

template<typename T>
class BinarySearchTree {
    private:
    std::unique_ptr<Node<T>> root;


    public:
    bool insert(T value) {
        if(root == nullptr) {
            root = std::make_unique<Node<T>>(value);
            return true;
        }
        return false;
    } 
};
