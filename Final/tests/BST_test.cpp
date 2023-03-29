#include "BST.h"
#include <gtest/gtest.h>

BinarySearchTree<int> create_simple_tree() {
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(14);
    tree.insert(13);
    tree.insert(1);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    return tree;
}

TEST(TestInsertValid, RootNode)
{

    BinarySearchTree<int> tree;

    ASSERT_TRUE(tree.insert(10));
}

TEST(TestInsertValid, LeftLeafNode) {
    BinarySearchTree<int> tree;
    tree.insert(10);
    ASSERT_TRUE(tree.insert(8));
}

TEST(TestInsertValid, RightLeafNode)
{
    BinarySearchTree<int> tree;
    tree.insert(10);
    ASSERT_TRUE(tree.insert(8));
}

TEST(TestInsertValid, DeeplyNestedTree) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.insert(3));
    ASSERT_TRUE(tree.insert(8));
    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.insert(14));
    ASSERT_TRUE(tree.insert(13));
    ASSERT_TRUE(tree.insert(1));
    ASSERT_TRUE(tree.insert(6));
    ASSERT_TRUE(tree.insert(4));
    ASSERT_TRUE(tree.insert(7));
}

TEST(TestInsertInvalid, DeeplyNestedTree)
{
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.insert(3));
    ASSERT_FALSE(tree.insert(3));
    ASSERT_TRUE(tree.insert(8));
    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.insert(14));
    ASSERT_TRUE(tree.insert(13));
    ASSERT_FALSE(tree.insert(13));
    ASSERT_TRUE(tree.insert(1));
    ASSERT_TRUE(tree.insert(6));
    ASSERT_TRUE(tree.insert(4));
    ASSERT_TRUE(tree.insert(7));
    ASSERT_FALSE(tree.insert(7));
}

TEST(TestHasValueValid, DeeplyNestedTree) {
    BinarySearchTree<int> tree;
    tree.insert(8);
    ASSERT_TRUE(tree.has_value(8));
    tree.insert(3);
    ASSERT_TRUE(tree.has_value(3));
    tree.insert(10);
    ASSERT_TRUE(tree.has_value(10));
    tree.insert(14);
    ASSERT_TRUE(tree.has_value(14));
    tree.insert(13);
    ASSERT_TRUE(tree.has_value(13));
    tree.insert(1);
    ASSERT_TRUE(tree.has_value(1));
    tree.insert(6);
    ASSERT_TRUE(tree.has_value(6));
    tree.insert(4);
    ASSERT_TRUE(tree.has_value(4));
    tree.insert(7);
    ASSERT_TRUE(tree.has_value(7));
}

TEST(TestHasValueInvalid, EmptyTree) {
    BinarySearchTree<int> tree;
    ASSERT_FALSE(tree.has_value(10));
}

TEST(TestHasValueInvalid, RootOnly)
{
    BinarySearchTree<int> tree;
    tree.insert(99);
    ASSERT_FALSE(tree.has_value(10));
}

TEST(TestHasValueInvalid, DeeplyNestedTree)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.has_value(100));
}

TEST(TestMaximum, NoParamValid) {
    BinarySearchTree<int> tree = create_simple_tree();
    int maximum = tree.maximum().value();
    ASSERT_EQ(maximum, 14);
}

TEST(TestMaximum, NoParamInvalid) {
    BinarySearchTree<int> tree;
    int maximum = tree.maximum().value_or(-12312312);
    ASSERT_EQ(maximum, -12312312);
}

TEST(TestMaximum, WithParamInvalidEmptyTree)
{
    BinarySearchTree<int> tree;
    int maximum = tree.maximum(10).value_or(-12312312);
    ASSERT_EQ(maximum, -12312312);
}

TEST(TestMaximum, WithParamInvalidNoNode)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int maximum = tree.maximum(20).value_or(-12312312);
    ASSERT_EQ(maximum, -12312312);
}

TEST(TestMaximum, WithParamValidRoot) {
    BinarySearchTree<int> tree = create_simple_tree();
    int maximum = tree.maximum(8).value();
    ASSERT_EQ(maximum, 14);
}

TEST(TestMaximum, WithParamValidMiddleNode)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int maximum = tree.maximum(3).value();
    ASSERT_EQ(maximum, 7);
}

TEST(TestMaximum, WithParamValidLeafNode)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int maximum = tree.maximum(4).value();
    ASSERT_EQ(maximum, 4);
}

TEST(TestMinimum, NoParamValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int minimum = tree.minimum().value();
    ASSERT_EQ(minimum, 1);
}

TEST(TestMinimum, NoParamInvalid)
{
    BinarySearchTree<int> tree;
    int minimum = tree.minimum().value_or(-12312312);
    ASSERT_EQ(minimum, -12312312);
}

TEST(TestMinimum, WithParamInvalidEmptyTree)
{
    BinarySearchTree<int> tree;
    int minimum = tree.minimum(10).value_or(-12312312);
    ASSERT_EQ(minimum, -12312312);
}

TEST(TestMinimum, WithParamInvalidNoNode)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int minimum = tree.minimum(20).value_or(-12312312);
    ASSERT_EQ(minimum, -12312312);
}

TEST(TestMinimum, WithParamValidRoot)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int minimum = tree.minimum(6).value();
    ASSERT_EQ(minimum, 4);
}

TEST(TestMinimum, WithParamValidMiddleNode)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int minimum = tree.minimum(10).value();
    ASSERT_EQ(minimum, 10);
}

TEST(TestMinimum, WithParamValidLeafNode)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int minimum = tree.minimum(7).value();
    ASSERT_EQ(minimum, 7);
}
