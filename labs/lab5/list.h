#pragma once

namespace lab5 {
    
    class List {
        public:
            struct Node{
                Node * next;
                int value;
            };

            Node * at(int index) const;
            int size() const;
            void push_front(int value);
            void insert(int index, int value);
            Node * erase(int value);

        private:
            Node * head;     
    };
}
