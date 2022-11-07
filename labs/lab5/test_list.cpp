#include <gtest/gtest.h>

#include "list.h"

using namespace lab5;

TEST(TestClassNewList, Empty)
{
    List list{};
    ASSERT_EQ(list.at(0), nullptr);
    ASSERT_EQ(list.size(), 0);
}

TEST(TestClassPushFront, AddOne)
{
    List list{};
    list.push_front(42);
    ASSERT_EQ(list.size(), 1);

    List::Node *node = list.at(0);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 42);
}

TEST(TestClassPushFront, AddMultiple)
{
    List list{};

    for (int i = 9; i >= 0; --i)
    {
        list.push_front(i);
    }
    EXPECT_EQ(list.size(), 10);

    for (int i = 0; i <= 9; ++i)
    {
        List::Node *node = list.at(i);
        ASSERT_NE(node, nullptr);
        ASSERT_EQ(node->value, i);
    }
}

TEST(TestClassInsert, InsertToEmpty)
{
    List list{};
    list.insert(0, 42);
    EXPECT_EQ(list.size(), 1);

    List::Node *node = list.at(0);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 42);
}

TEST(TestClassInsert, InsertToFront)
{
    List list{};

    list.push_front(1);
    list.push_front(2);
    ASSERT_EQ(list.size(), 2);

    list.insert(0, 42);
    ASSERT_EQ(list.size(), 3);

    List::Node *node = list.at(0);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 42);
}

TEST(TestClassInsert, InsertToBack)
{
    List list{};

    list.push_front(1);
    list.push_front(2);
    EXPECT_EQ(list.size(), 2);

    int back_index = list.size();
    list.insert(back_index, 42);
    EXPECT_EQ(list.size(), 3);

    List::Node *node = list.at(back_index);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 42);
}

TEST(TestClassInsert, InsertToMiddle)
{
    List list{};

    list.push_front(1);
    list.push_front(2);
    EXPECT_EQ(list.size(), 2);

    list.insert(1, 42);
    EXPECT_EQ(list.size(), 3);

    List::Node *node = list.at(1);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 42);
}

TEST(TestClassErase, EraseEmpty)
{
    List list{};

    ASSERT_EQ(list.erase(10), nullptr);
}

TEST(TestClassHeadErase, EraseHead)
{
    List list{};

    list.push_front(10);
    list.push_front(11);

    List::Node *deleted = list.erase(11);

    EXPECT_EQ(list.size(), 1);
    ASSERT_EQ(deleted->value, 11);
    ASSERT_EQ(list.at(0)->value, 10);
}

TEST(TestClassEraseMiddle, EraseMiddle)
{
    List list{};

    list.push_front(10);
    list.push_front(11);
    list.push_front(12);
    list.push_front(13);

    List::Node * deleted = list.erase(12);
    EXPECT_EQ(list.size(), 3);
    ASSERT_EQ(deleted->value, 12);
    ASSERT_EQ(list.at(0)->next->value, 11);
}

TEST(TestClassEraseEnd, EraseEnd) {
    List list{};

    list.push_front(10);
    list.push_front(11);
    list.push_front(12);
    list.push_front(13);

    List::Node * deleted = list.erase(10);
    EXPECT_EQ(list.size(), 3);
    ASSERT_EQ(deleted->value, 10);
    ASSERT_EQ(list.at(2)->next, nullptr);
}
