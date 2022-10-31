#include "linked_list.h"

namespace lab3 {

List new_list() {
    return List{};
}

Node * at(List list, int index) {
        
    Node* current = list.head;
 
    int count = 0;
    while (current != nullptr) {
        if (count == index)
            return (current);
        count++;
        current = current->next;
    }
    return nullptr;
}

int size(List list) {
    int count = 0;
    Node * current = list.head;
    while(current != nullptr){
        ++count;
        current = current->next;
    }
    return count;
}

void push_front(List & list, int value) {
    Node * node = new Node();
    node->value = value;
    node->next = list.head;
    list.head = node;
}

Node * insert(List & list, int index, int value) {
    return nullptr;
}

Node * erase(List & list, int value) {
    return nullptr;
}

}