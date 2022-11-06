#include <gtest/gtest.h>

#include "list.h"

using namespace lab6;

struct TestList : testing::TestWithParam<List *> {

};

TEST_P(TestList, Empty) {
    auto list = GetParam();
    ASSERT_EQ(list->size(), 0);
}

TEST_P(TestList, AddOne) {
    auto list = GetParam();
    list->push_front(42);
    ASSERT_EQ(list->size(), 1);
    ASSERT_EQ(list->at(0), 42);
}

TEST_P(TestList, AddMultiple) {
    auto list = GetParam();

    for (int i = 9; i >= 0; --i) {
        list->push_front(i);
    }
    ASSERT_EQ(list->size(), 10);
    
    for (int i = 0; i <= 9; ++i) {
        ASSERT_EQ(list->at(i), i);
    }
}

TEST_P(TestList, InsertToEmpty) {
    auto list = GetParam();
    list->insert(0, 42);
    ASSERT_EQ(list->size(), 1);
    ASSERT_EQ(list->at(0), 42);
}

TEST_P(TestList, InsertToFront) {
    auto list = GetParam();

    list->push_front(1);
    list->push_front(2);
    ASSERT_EQ(list->size(), 2);
    
    list->insert(0, 42);
    ASSERT_EQ(list->size(), 3);
    ASSERT_EQ(list->at(0), 42);
}

TEST_P(TestList, InsertToBack) {
    auto list = GetParam();

    list->push_front(1);
    list->push_front(2);
    ASSERT_EQ(list->size(), 2);
    
    int back_index = list->size();
    list->insert(back_index, 42);
    ASSERT_EQ(list->size(), 3);
    ASSERT_EQ(list->at(back_index), 42);
}

TEST_P(TestList, InsertToMiddle) {
    auto list = GetParam();

    list->push_front(1);
    list->push_front(2);
    ASSERT_EQ(list->size(), 2);
    
    list->insert(1, 42);
    ASSERT_EQ(list->size(), 3);
    ASSERT_EQ(list->at(1), 42);
}

TEST_P(TestList, EraseFromFront) {
    auto list = GetParam();

    list->push_front(1);
    list->push_front(2);
    ASSERT_EQ(list->size(), 2);

    list->erase(0);
    ASSERT_EQ(list->size(), 1);
    ASSERT_EQ(list->at(0), 1);
}

TEST_P(TestList, EraseFromBack) {
    auto list = GetParam();

    list->push_front(1);
    list->push_front(2);
    ASSERT_EQ(list->size(), 2);

    list->erase(1);
    ASSERT_EQ(list->size(), 1);
    ASSERT_EQ(list->at(0), 2);
}

TEST_P(TestList, EraseFromMiddle) {
    auto list = GetParam();

    list->push_front(1);
    list->push_front(2);
    list->push_front(3);
    ASSERT_EQ(list->size(), 3);

    list->erase(1);
    ASSERT_EQ(list->size(), 2);
    ASSERT_EQ(list->at(0), 3);
    ASSERT_EQ(list->at(1), 1);
}

INSTANTIATE_TEST_SUITE_P(TestListImplementations, TestList, testing::Values(
    new_single_linked_list()
    // TODO(Task 3.2)
    //, new_vector_list()
));
