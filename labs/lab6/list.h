#pragma once

namespace lab6 {
    
    struct List {
        virtual int at(int index) const = 0;
        virtual int size() const = 0;
        virtual void push_front(int value) = 0;
        virtual void insert(int index, int value) = 0;
        virtual void erase(int index) = 0;
    };

    List * new_single_linked_list();
}
