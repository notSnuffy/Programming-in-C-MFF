#include <AVL.h>
#include <gtest/gtest.h>

AVLTree<int> create_simple_tree()
{
    AVLTree<int> tree;
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

    AVLTree<int> tree;

    ASSERT_TRUE(tree.insert(10));
}

TEST(TestInsertValid, LeftLeafNode)
{
    AVLTree<int> tree;
    tree.insert(10);
    ASSERT_TRUE(tree.insert(8));
}

TEST(TestInsertValid, RightLeafNode)
{
    AVLTree<int> tree;
    tree.insert(10);
    ASSERT_TRUE(tree.insert(8));
}

TEST(TestInsertValid, DeeplyNestedTree)
{
    AVLTree<int> tree;
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
    AVLTree<int> tree;
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

TEST(TestHasValueValid, DeeplyNestedTree)
{
    AVLTree<int> tree;
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

TEST(TestHasValueInvalid, EmptyTree)
{
    AVLTree<int> tree;
    ASSERT_FALSE(tree.has_value(10));
}

TEST(TestHasValueInvalid, RootOnly)
{
    AVLTree<int> tree;
    tree.insert(99);
    ASSERT_FALSE(tree.has_value(10));
}

TEST(TestHasValueInvalid, DeeplyNestedTree)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.has_value(100));
}

TEST(TestLeftChildValue, NoNodeInvalid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.left_child_value(100).has_value());
}

TEST(TestLeftChildValue, NoLeftChildInvalid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.left_child_value(1).has_value());
}

TEST(TestLeftChildValue, LeftChildValid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_EQ(tree.left_child_value(8), 3);
}

TEST(TestRightChildValue, NoNodeInvalid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.right_child_value(100).has_value());
}

TEST(TestRightChildValue, NoRightChildInvalid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.right_child_value(1).has_value());
}

TEST(TestRightChildValue, RightChildValid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_EQ(tree.right_child_value(8), 13);
}

TEST(TestParentValue, NoNodeInvalid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.parent_value(100).has_value());
}

TEST(TestParentValue, NoParentInvalid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.parent_value(8).has_value());
}

TEST(TestParentValue, ParentValid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_EQ(tree.parent_value(3), 8);
}

TEST(TestMaximum, NoParamValid)
{
    AVLTree<int> tree = create_simple_tree();
    int maximum = tree.maximum().value();
    ASSERT_EQ(maximum, 14);
}

TEST(TestMaximum, NoParamInvalid)
{
    AVLTree<int> tree;
    ASSERT_FALSE(tree.maximum().has_value());
}

TEST(TestMaximum, WithParamInvalidEmptyTree)
{
    AVLTree<int> tree;
    ASSERT_FALSE(tree.maximum(10).has_value());
}

TEST(TestMaximum, WithParamInvalidNoNode)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.maximum(20).has_value());
}

TEST(TestMaximum, WithParamValidRoot)
{
    AVLTree<int> tree = create_simple_tree();
    int maximum = tree.maximum(8).value();
    ASSERT_EQ(maximum, 14);
}

TEST(TestMaximum, WithParamValidMiddleNode)
{
    AVLTree<int> tree = create_simple_tree();
    int maximum = tree.maximum(3).value();
    ASSERT_EQ(maximum, 7);
}

TEST(TestMaximum, WithParamValidLeafNode)
{
    AVLTree<int> tree = create_simple_tree();
    int maximum = tree.maximum(4).value();
    ASSERT_EQ(maximum, 4);
}

TEST(TestMinimum, NoParamValid)
{
    AVLTree<int> tree = create_simple_tree();
    int minimum = tree.minimum().value();
    ASSERT_EQ(minimum, 1);
}

TEST(TestMinimum, NoParamInvalid)
{
    AVLTree<int> tree;
    ASSERT_FALSE(tree.minimum().has_value());
}

TEST(TestMinimum, WithParamInvalidEmptyTree)
{
    AVLTree<int> tree;
    ASSERT_FALSE(tree.minimum(10).has_value());
}

TEST(TestMinimum, WithParamInvalidNoNode)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.minimum(20).has_value());
}

TEST(TestMinimum, WithParamValidRoot)
{
    AVLTree<int> tree = create_simple_tree();
    int minimum = tree.minimum(6).value();
    ASSERT_EQ(minimum, 4);
}

TEST(TestMinimum, WithParamValidMiddleNode)
{
    AVLTree<int> tree = create_simple_tree();
    int minimum = tree.minimum(10).value();
    ASSERT_EQ(minimum, 10);
}

TEST(TestMinimum, WithParamValidLeafNode)
{
    AVLTree<int> tree = create_simple_tree();
    int minimum = tree.minimum(7).value();
    ASSERT_EQ(minimum, 7);
}

TEST(TestSuccessor, NoNodeInvalid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.successor(100).has_value());
}

TEST(TestSuccessor, EmptyTreeInvalid)
{
    AVLTree<int> tree;
    ASSERT_FALSE(tree.successor(100).has_value());
}

TEST(TestSuccessor, NoSuccessorInvalid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.successor(14).has_value());
}

TEST(TestSuccessor, RootNodeValid)
{
    AVLTree<int> tree = create_simple_tree();
    int successor = tree.successor(8).value();
    ASSERT_EQ(successor, 10);
}

TEST(TestSuccessor, MiddleNodeValid)
{
    AVLTree<int> tree = create_simple_tree();
    int successor = tree.successor(10).value();
    ASSERT_EQ(successor, 13);
}

TEST(TestSuccessor, LeftLeafNodeValid)
{
    AVLTree<int> tree = create_simple_tree();
    int successor = tree.successor(4).value();
    ASSERT_EQ(successor, 6);
}

TEST(TestSuccessor, RightLeafNodeValid)
{
    AVLTree<int> tree = create_simple_tree();
    int successor = tree.successor(7).value();
    ASSERT_EQ(successor, 8);
}

TEST(TestPredecessor, NoNodeInvalid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.predecessor(100).has_value());
}

TEST(TestPredecessor, EmptyTreeInvalid)
{
    AVLTree<int> tree;
    ASSERT_FALSE(tree.predecessor(100).has_value());
}

TEST(TestPredecessor, NoPredecessorInvalid)
{
    AVLTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.predecessor(1).has_value());
}

TEST(TestPredecessor, RootNodeValid)
{
    AVLTree<int> tree = create_simple_tree();
    int predecessor = tree.predecessor(8).value();
    ASSERT_EQ(predecessor, 7);
}

TEST(TestPredecessor, MiddleNodeValid)
{
    AVLTree<int> tree = create_simple_tree();
    int predecessor = tree.predecessor(10).value();
    ASSERT_EQ(predecessor, 8);
}

TEST(TestPredecessor, LeftLeafNodeValid)
{
    AVLTree<int> tree = create_simple_tree();
    int predecessor = tree.predecessor(4).value();
    ASSERT_EQ(predecessor, 3);
}

TEST(TestPredecessor, RightLeafNodeValid)
{
    AVLTree<int> tree = create_simple_tree();
    int predecessor = tree.predecessor(7).value();
    ASSERT_EQ(predecessor, 6);
}
