#include <gtest/gtest.h>

#include "linked_list.h"

using namespace lab3;

TEST(TestNewList, Empty) {
    List list = new_list();
    ASSERT_EQ(list.head, nullptr);
    ASSERT_EQ(size(list), 0);
}

TEST(TestPushFront, AddOne) {
    List list = new_list();
    push_front(list, 42);
    ASSERT_EQ(size(list), 1);
    
    Node * node = at(list, 0);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 42);
}

TEST(TestPushFront, AddMultiple) {
    List list = new_list();

    for (int i = 9; i >= 0; --i) {
        push_front(list, i);
    }
    EXPECT_EQ(size(list), 10);
    
    for (int i = 0; i <= 9; ++i) {
        Node * node = at(list, i);
        ASSERT_NE(node, nullptr);
        ASSERT_EQ(node->value, i);
    }
}

TEST(TestInsert, InsertToEmpty) {
    List list = new_list();
    insert(list, 0, 42);
    EXPECT_EQ(size(list), 1);

    Node * node = at(list, 0);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 42);
}

TEST(TestInsert, InsertToFront) {
    List list = new_list();

    push_front(list, 1);
    push_front(list, 2);
    ASSERT_EQ(size(list), 2);
    
    insert(list, 0, 42);
    ASSERT_EQ(size(list), 3);

    Node * node = at(list, 0);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 42);
}

TEST(TestInsert, InsertToBack) {
    List list = new_list();

    push_front(list, 1);
    push_front(list, 2);
    EXPECT_EQ(size(list), 2);
    
    int back_index = size(list);
    insert(list, back_index, 42);
    EXPECT_EQ(size(list), 3);

    Node * node = at(list, back_index);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 42);
}

TEST(TestInsert, InsertToMiddle) {
    List list = new_list();

    push_front(list, 1);
    push_front(list, 2);
    EXPECT_EQ(size(list), 2);
    
    insert(list, 1, 42);
    EXPECT_EQ(size(list), 3);

    Node * node = at(list, 1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 42);
}
