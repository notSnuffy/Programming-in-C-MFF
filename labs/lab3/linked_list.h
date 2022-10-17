#pragma once

namespace lab3 {

struct Node {
    Node * next;
    int value;
};

struct List {
    Node * head;
    Node * current;
};

List new_list();

Node * at(List list, int index);

int size(List list);

void push_front(List list, int value);

Node * insert(List list, int index, int value);

Node * erase(List list, int value);

} // namespace lab3
