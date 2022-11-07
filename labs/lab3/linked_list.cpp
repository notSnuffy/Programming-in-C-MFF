#include "linked_list.h"

namespace lab3
{

    List new_list()
    {
        return List{};
    }

    Node *at(List list, int index)
    {

        Node *current = list.head;

        int count = 0;
        while (current != nullptr)
        {
            if (count == index)
                return (current);
            count++;
            current = current->next;
        }
        return nullptr;
    }

    int size(List list)
    {
        int count = 0;
        Node *current = list.head;
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }

    void push_front(List &list, int value)
    {
        Node *node = new Node();
        node->value = value;
        node->next = list.head;
        list.head = node;
    }

    void insert_to_list(List &list, int index, int value)
    {
        Node *node = new Node();
        node->value = value;

        if (index == 0)
        {
            push_front(list, value);
            return;
        }

        if (list.head == nullptr)
            return;

        if (index < size(list))
        {
            Node *temp = list.head;
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
            return;
        }

        if (index == size(list))
        {
            Node *temp = list.head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
            return;
        }
    }

    Node *erase(List &list, int value)
    {
        return nullptr;
    }

}
