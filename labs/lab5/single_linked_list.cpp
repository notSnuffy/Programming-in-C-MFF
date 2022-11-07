#include "list.h"

namespace lab5
{

    List::Node *List::at(int index) const
    {
        Node *current = this->head;

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

    int List::size() const
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

    void List::push_front(int value)
    {
        Node *node = new Node();
        node->value = value;
        node->next = this->head;
        this->head = node;
    }

    void List::insert(int index, int value)
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

    List::Node *List::erase(int value)
    {
        if (head == nullptr)
            return nullptr;
        if (head->value == value)
        {
            Node *retNode = head;
            head = head->next;
            return retNode;
        }
        Node *temp = head;
        while (temp->next != nullptr && value != temp->next->value)
        {
            temp = temp->next;
        }

        if (temp->next != nullptr)
        {
            Node *deleted = temp->next;
            temp->next = temp->next->next;
            return deleted;
        }
        return nullptr;
    }

}
