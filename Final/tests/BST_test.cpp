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
    ASSERT_FALSE(tree.maximum().has_value());
}

TEST(TestMaximum, WithParamInvalidEmptyTree)
{
    BinarySearchTree<int> tree;
    ASSERT_FALSE(tree.maximum(10).has_value());
}

TEST(TestMaximum, WithParamInvalidNoNode)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.maximum(20).has_value());
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
    ASSERT_FALSE(tree.minimum().has_value());
}

TEST(TestMinimum, WithParamInvalidEmptyTree)
{
    BinarySearchTree<int> tree;
    ASSERT_FALSE(tree.minimum(10).has_value());
}

TEST(TestMinimum, WithParamInvalidNoNode)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.minimum(20).has_value());
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

TEST(TestSuccessor, NoNodeInvalid) {
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.successor(100).has_value());
}

TEST(TestSuccessor, EmptyTreeInvalid) {
    BinarySearchTree<int> tree;
    ASSERT_FALSE(tree.successor(100).has_value());
}

TEST(TestSuccessor, NoSuccessorInvalid) {
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.successor(14).has_value());
}

TEST(TestSuccessor, RootNodeValid) {
    BinarySearchTree<int> tree = create_simple_tree();
    int successor = tree.successor(8).value();
    ASSERT_EQ(successor, 10);
}


TEST(TestSuccessor, MiddleNodeValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int successor = tree.successor(10).value();
    ASSERT_EQ(successor, 13);
}

TEST(TestSuccessor, LeftLeafNodeValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int successor = tree.successor(4).value();
    ASSERT_EQ(successor, 6);
}

TEST(TestSuccessor, RightLeafNodeValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int successor = tree.successor(7).value();
    ASSERT_EQ(successor, 8);
}

TEST(TestPredecessor, NoNodeInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.predecessor(100).has_value());
}

TEST(TestPredecessor, EmptyTreeInvalid)
{
    BinarySearchTree<int> tree;
    ASSERT_FALSE(tree.predecessor(100).has_value());
}

TEST(TestPredecessor, NoPredecessorInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.predecessor(1).has_value());
}

TEST(TestPredecessor, RootNodeValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int predecessor = tree.predecessor(8).value();
    ASSERT_EQ(predecessor, 7);
}

TEST(TestPredecessor, MiddleNodeValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int predecessor = tree.predecessor(10).value();
    ASSERT_EQ(predecessor, 8);
}

TEST(TestPredecessor, LeftLeafNodeValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int predecessor = tree.predecessor(4).value();
    ASSERT_EQ(predecessor, 3);
}

TEST(TestPredecessor, RightLeafNodeValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int predecessor = tree.predecessor(7).value();
    ASSERT_EQ(predecessor, 6);
}
