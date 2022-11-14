#include "list.h"

namespace lab6 {

struct SingleLinkedList : List {
    struct Node{
        Node * next;
        int value;
    };

    Node * head;

    SingleLinkedList() : head(nullptr){

    }

    SingleLinkedList(SingleLinkedList & other) : head(other.head){

    }
    SingleLinkedList & operator=(SingleLinkedList & other) {
        this->head = other.head;
    }

    ~SingleLinkedList() {
        Node * current = this->head;
        while(current != nullptr) {
            Node * next = current->next;
            delete current;
            current = next;
        }
    }

    int at(int index) const override
    {
        Node *current = this->head;

        int count = 0;
        while (current != nullptr)
        {
            if (count == index)
                return current->value;
            count++;
            current = current->next;
        }
        return 0;
    }

    int size() const override
    {
        int count = 0;
        Node *current = this->head;
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }

    void push_front(int value) override
    {
        Node *node = new Node();
        node->value = value;
        node->next = this->head;
        this->head = node;
    }

    void insert(int index, int value) override
    {
        Node *node = new Node();
        node->value = value;

        if (index == 0)
        {
            push_front(value);
            return;
        }

        if (head == nullptr)
            return;

        if (index < size())
        {
            Node *temp = head;
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
            return;
        }

        if (index == size())
        {
            Node *temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    void erase(int index) override
    {
        Node * current = head;
        if (index == 0) {
            if (!head) {
                return;
            }
            head = head->next;
            return;;
        }

        Node * previous = nullptr;
        for (int i = 0; i < index; ++i) {
            if (!current) {
                return;
            }
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        return;
    }

};

List * new_single_linked_list(){
    return new SingleLinkedList{};
}

}
