#include <BST.h>
#include <gtest/gtest.h>
#include <vector>
#include <numeric>

BinarySearchTree<int> create_simple_tree()
{
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

TEST(TestInsertValid, LeftLeafNode)
{
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

TEST(TestInsertValid, DeeplyNestedTree)
{
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

TEST(TestHasValueValid, DeeplyNestedTree)
{
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

TEST(TestHasValueInvalid, EmptyTree)
{
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

TEST(TestLeftChildValue, NoNodeInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.left_child_value(100).has_value());
}

TEST(TestLeftChildValue, NoLeftChildInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.left_child_value(1).has_value());
}

TEST(TestLeftChildValue, LeftChildValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_EQ(tree.left_child_value(8), 3);
}

TEST(TestRightChildValue, NoNodeInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.right_child_value(100).has_value());
}

TEST(TestRightChildValue, NoRightChildInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.right_child_value(1).has_value());
}

TEST(TestRightChildValue, RightChildValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_EQ(tree.right_child_value(8), 10);
}

TEST(TestParentValue, NoNodeInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.parent_value(100).has_value());
}

TEST(TestParentValue, NoParentInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.parent_value(8).has_value());
}

TEST(TestParentValue, ParentValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_EQ(tree.parent_value(3), 8);
}

TEST(TestMaximum, NoParamValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    int maximum = tree.maximum().value();
    ASSERT_EQ(maximum, 14);
}

TEST(TestMaximum, NoParamInvalid)
{
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

TEST(TestMaximum, WithParamValidRoot)
{
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

TEST(TestSuccessor, NoNodeInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.successor(100).has_value());
}

TEST(TestSuccessor, EmptyTreeInvalid)
{
    BinarySearchTree<int> tree;
    ASSERT_FALSE(tree.successor(100).has_value());
}

TEST(TestSuccessor, NoSuccessorInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.successor(14).has_value());
}

TEST(TestSuccessor, RootNodeValid)
{
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

TEST(TestRemove, NoNodeInvalid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_FALSE(tree.remove(100));
    ASSERT_TRUE(tree.has_value(8));
    ASSERT_TRUE(tree.has_value(3));
    ASSERT_TRUE(tree.has_value(10));
    ASSERT_TRUE(tree.has_value(14));
    ASSERT_TRUE(tree.has_value(13));
    ASSERT_TRUE(tree.has_value(1));
    ASSERT_TRUE(tree.has_value(6));
    ASSERT_TRUE(tree.has_value(4));
    ASSERT_TRUE(tree.has_value(7));
}

TEST(TestRemove, NoChildrenRootValid)
{
    BinarySearchTree<int> tree;
    tree.insert(10);
    ASSERT_TRUE(tree.has_value(10));
    ASSERT_TRUE(tree.remove(10));
    ASSERT_FALSE(tree.has_value(10));
    ASSERT_FALSE(tree.maximum());
}

TEST(TestRemove, NoChildrenLeftChildValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_TRUE(tree.remove(1));
    ASSERT_FALSE(tree.has_value(1));
    ASSERT_FALSE(tree.predecessor(3));
    ASSERT_EQ(tree.successor(3), 4);
    ASSERT_FALSE(tree.left_child_value(3));
    ASSERT_EQ(tree.right_child_value(3), 6);

    ASSERT_TRUE(tree.has_value(8));
    ASSERT_TRUE(tree.has_value(3));
    ASSERT_TRUE(tree.has_value(10));
    ASSERT_TRUE(tree.has_value(14));
    ASSERT_TRUE(tree.has_value(13));
    ASSERT_TRUE(tree.has_value(6));
    ASSERT_TRUE(tree.has_value(4));
    ASSERT_TRUE(tree.has_value(7));
}

TEST(TestRemove, NoChildrenRightChildValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_TRUE(tree.remove(7));
    ASSERT_FALSE(tree.has_value(7));
    ASSERT_EQ(tree.successor(6), 8);
    ASSERT_EQ(tree.predecessor(6), 4);
    ASSERT_FALSE(tree.right_child_value(6));
    ASSERT_EQ(tree.left_child_value(6), 4);

    ASSERT_TRUE(tree.has_value(8));
    ASSERT_TRUE(tree.has_value(3));
    ASSERT_TRUE(tree.has_value(10));
    ASSERT_TRUE(tree.has_value(14));
    ASSERT_TRUE(tree.has_value(13));
    ASSERT_TRUE(tree.has_value(6));
    ASSERT_TRUE(tree.has_value(4));
    ASSERT_TRUE(tree.has_value(1));
}

TEST(TestRemove, OneLeftChildRootValid)
{
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    ASSERT_EQ(tree.parent_value(3), 8);

    ASSERT_TRUE(tree.remove(8));
    ASSERT_FALSE(tree.has_value(8));
    ASSERT_EQ(tree.maximum(), 7);
    ASSERT_EQ(tree.successor(3), 4);
    ASSERT_EQ(tree.predecessor(3), 1);
    ASSERT_EQ(tree.left_child_value(3), 1);
    ASSERT_EQ(tree.right_child_value(3), 6);
    ASSERT_FALSE(tree.parent_value(3).has_value());

    ASSERT_TRUE(tree.has_value(3));
    ASSERT_TRUE(tree.has_value(6));
    ASSERT_TRUE(tree.has_value(7));
    ASSERT_TRUE(tree.has_value(4));
    ASSERT_TRUE(tree.has_value(1));
}

TEST(TestRemove, OneRightChildRootValid)
{
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(10);
    tree.insert(14);
    tree.insert(13);
    ASSERT_EQ(tree.parent_value(10), 8);

    ASSERT_TRUE(tree.remove(8));
    ASSERT_FALSE(tree.has_value(8));
    ASSERT_EQ(tree.minimum(), 10);
    ASSERT_EQ(tree.successor(10), 13);
    ASSERT_FALSE(tree.predecessor(10));
    ASSERT_FALSE(tree.left_child_value(10).has_value());
    ASSERT_EQ(tree.right_child_value(10), 14);
    ASSERT_FALSE(tree.parent_value(10).has_value());

    ASSERT_TRUE(tree.has_value(10));
    ASSERT_TRUE(tree.has_value(13));
    ASSERT_TRUE(tree.has_value(14));
}

TEST(TestRemove, OneLeftChildAndDeletedIsLeftChildValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    tree.insert(0);
    ASSERT_TRUE(tree.remove(1));
    ASSERT_FALSE(tree.has_value(1));
    ASSERT_EQ(tree.minimum(), 0);
    ASSERT_EQ(tree.successor(3), 4);
    ASSERT_EQ(tree.predecessor(3), 0);
    ASSERT_FALSE(tree.predecessor(0));

    ASSERT_EQ(tree.parent_value(0), 3);
    ASSERT_FALSE(tree.right_child_value(0));
    ASSERT_FALSE(tree.left_child_value(0));
    ASSERT_EQ(tree.left_child_value(3), 0);
    ASSERT_EQ(tree.right_child_value(3), 6);
    ASSERT_EQ(tree.parent_value(3), 8);

    ASSERT_TRUE(tree.has_value(0));
    ASSERT_TRUE(tree.has_value(3));
    ASSERT_TRUE(tree.has_value(4));
    ASSERT_TRUE(tree.has_value(6));
    ASSERT_TRUE(tree.has_value(7));
    ASSERT_TRUE(tree.has_value(8));
    ASSERT_TRUE(tree.has_value(10));
    ASSERT_TRUE(tree.has_value(13));
    ASSERT_TRUE(tree.has_value(14));
}

TEST(TestRemove, OneLeftChildAndDeletedIsRightChildValid)
{
    BinarySearchTree<int> tree = create_simple_tree();

    ASSERT_EQ(tree.parent_value(13), 14);

    ASSERT_TRUE(tree.remove(14));
    ASSERT_FALSE(tree.has_value(14));
    ASSERT_EQ(tree.maximum(), 13);
    ASSERT_FALSE(tree.successor(13).has_value());
    ASSERT_EQ(tree.predecessor(13), 10);

    ASSERT_EQ(tree.parent_value(13), 10);
    ASSERT_FALSE(tree.right_child_value(13));
    ASSERT_FALSE(tree.left_child_value(13));
    ASSERT_EQ(tree.right_child_value(10), 13);
    ASSERT_FALSE(tree.left_child_value(10).has_value());
    ASSERT_EQ(tree.parent_value(10), 8);

    ASSERT_TRUE(tree.has_value(3));
    ASSERT_TRUE(tree.has_value(4));
    ASSERT_TRUE(tree.has_value(6));
    ASSERT_TRUE(tree.has_value(7));
    ASSERT_TRUE(tree.has_value(8));
    ASSERT_TRUE(tree.has_value(10));
    ASSERT_TRUE(tree.has_value(13));
}

TEST(TestRemove, OneRightChildAndDeletedIsLeftChildValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    tree.remove(1);

    ASSERT_EQ(tree.parent_value(6), 3);

    ASSERT_TRUE(tree.remove(3));
    ASSERT_FALSE(tree.has_value(3));
    ASSERT_EQ(tree.successor(4), 6);
    ASSERT_FALSE(tree.predecessor(4).has_value());

    ASSERT_EQ(tree.parent_value(6), 8);
    ASSERT_EQ(tree.left_child_value(6), 4);
    ASSERT_EQ(tree.right_child_value(6), 7);
    ASSERT_EQ(tree.right_child_value(8), 10);
    ASSERT_EQ(tree.left_child_value(8), 6);

    ASSERT_TRUE(tree.has_value(4));
    ASSERT_TRUE(tree.has_value(6));
    ASSERT_TRUE(tree.has_value(7));
    ASSERT_TRUE(tree.has_value(8));
    ASSERT_TRUE(tree.has_value(10));
    ASSERT_TRUE(tree.has_value(13));
}

TEST(TestRemove, OneRightChildAndDeletedIsRightChildValid)
{
    BinarySearchTree<int> tree = create_simple_tree();

    ASSERT_EQ(tree.parent_value(14), 10);

    ASSERT_TRUE(tree.remove(10));
    ASSERT_FALSE(tree.has_value(10));
    ASSERT_EQ(tree.successor(8), 13);
    ASSERT_EQ(tree.predecessor(13), 8);

    ASSERT_EQ(tree.parent_value(14), 8);
    ASSERT_EQ(tree.left_child_value(14), 13);
    ASSERT_FALSE(tree.right_child_value(14).has_value());
    ASSERT_EQ(tree.right_child_value(8), 14);
    ASSERT_EQ(tree.left_child_value(8), 3);

    ASSERT_TRUE(tree.has_value(1));
    ASSERT_TRUE(tree.has_value(4));
    ASSERT_TRUE(tree.has_value(6));
    ASSERT_TRUE(tree.has_value(7));
    ASSERT_TRUE(tree.has_value(8));
    ASSERT_TRUE(tree.has_value(13));
    ASSERT_TRUE(tree.has_value(14));
}

TEST(TestRemove, BothChildrenRootValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_TRUE(tree.remove(8));
    ASSERT_FALSE(tree.has_value(8));
    ASSERT_FALSE(tree.parent_value(10).has_value());
    ASSERT_EQ(tree.left_child_value(10), 3);
    ASSERT_EQ(tree.right_child_value(10), 14);
    ASSERT_EQ(tree.parent_value(3), 10);
    ASSERT_EQ(tree.left_child_value(3), 1);
    ASSERT_EQ(tree.right_child_value(3), 6);
    ASSERT_FALSE(tree.left_child_value(1).has_value());
    ASSERT_FALSE(tree.right_child_value(1).has_value());
    ASSERT_EQ(tree.parent_value(1), 3);
    ASSERT_EQ(tree.left_child_value(6), 4);
    ASSERT_EQ(tree.right_child_value(6), 7);
    ASSERT_EQ(tree.parent_value(6), 3);
    ASSERT_EQ(tree.parent_value(14), 10);
    ASSERT_EQ(tree.left_child_value(14), 13);
    ASSERT_FALSE(tree.right_child_value(14).has_value());
    ASSERT_EQ(tree.parent_value(13), 14);
    ASSERT_FALSE(tree.left_child_value(13).has_value());
    ASSERT_FALSE(tree.right_child_value(13).has_value());
}

TEST(TestRemove, BothChildrenMiddleNodeNestedSuccessorValid)
{
    BinarySearchTree<int> tree;

    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(9);
    tree.insert(14);
    tree.insert(13);
    tree.insert(1);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);

    ASSERT_TRUE(tree.remove(10));
    ASSERT_FALSE(tree.has_value(10));
    ASSERT_EQ(tree.parent_value(9), 13);
    ASSERT_FALSE(tree.left_child_value(9).has_value());
    ASSERT_FALSE(tree.right_child_value(9).has_value());
    ASSERT_EQ(tree.parent_value(3), 8);
    ASSERT_EQ(tree.left_child_value(3), 1);
    ASSERT_EQ(tree.right_child_value(3), 6);
    ASSERT_FALSE(tree.left_child_value(1).has_value());
    ASSERT_FALSE(tree.right_child_value(1).has_value());
    ASSERT_EQ(tree.parent_value(1), 3);
    ASSERT_EQ(tree.left_child_value(6), 4);
    ASSERT_EQ(tree.right_child_value(6), 7);
    ASSERT_EQ(tree.parent_value(6), 3);
    ASSERT_EQ(tree.parent_value(14), 13);
    ASSERT_FALSE(tree.left_child_value(14).has_value());
    ASSERT_FALSE(tree.right_child_value(14).has_value());
    ASSERT_FALSE(tree.parent_value(8).has_value());
    ASSERT_EQ(tree.left_child_value(8), 3);
    ASSERT_EQ(tree.right_child_value(8), 13);
}

TEST(TestRemove, DeleteWholeTreeValid)
{
    BinarySearchTree<int> tree = create_simple_tree();
    ASSERT_TRUE(tree.remove(8));
    ASSERT_TRUE(tree.remove(3));
    ASSERT_TRUE(tree.remove(10));
    ASSERT_TRUE(tree.remove(14));
    ASSERT_TRUE(tree.remove(13));
    ASSERT_TRUE(tree.remove(1));
    ASSERT_TRUE(tree.remove(6));
    ASSERT_TRUE(tree.remove(4));
    ASSERT_TRUE(tree.remove(7));
    ASSERT_FALSE(tree.maximum());
}

TEST(TestIterator, IteratorForwardValid)
{
    BinarySearchTree<int> tree = create_simple_tree();

    std::vector<int> expected = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    std::vector<int> actual;

    for (auto it = tree.begin(); it != tree.end(); ++it)
    {
        actual.push_back(*it);
    }

    ASSERT_EQ(expected, actual);
}

TEST(TestIterator, IteratorBackwardValid)
{
    BinarySearchTree<int> tree = create_simple_tree();

    std::vector<int> expected = {14, 13, 10, 8, 7, 6, 4, 3, 1};
    std::vector<int> actual;

    for (auto it = tree.rbegin(); it != tree.rend(); ++it)
    {
        actual.push_back(*it);
    }

    ASSERT_EQ(expected, actual);
}

TEST(TestIterator, IteratorForwardBackwardValid)
{
    BinarySearchTree<int> tree = create_simple_tree();

    std::vector<int> expected = {1, 3, 4, 6, 7, 8, 10, 13, 14, 13, 10, 8, 7, 6, 4, 3, 1};
    std::vector<int> actual;

    auto it = tree.begin();
    for (; *it != 14; ++it)
    {
        actual.push_back(*it);
    }

    for (; it != tree.begin(); --it)
    {
        actual.push_back(*it);
    }
    actual.push_back(*it);

    ASSERT_EQ(expected, actual);
}

TEST(TestIterator, IteratorAccumulateValid)
{
    BinarySearchTree<int> tree = create_simple_tree();

    int expected = 0;
    for (auto it = tree.begin(); it != tree.end(); ++it)
    {
        expected += *it;
    }

    int actual = std::accumulate(tree.begin(), tree.end(), 0);

    ASSERT_EQ(expected, actual);
}

TEST(TestIterator, RangeBasedForLoopValid)
{
    BinarySearchTree<int> tree = create_simple_tree();

    std::vector<int> expected = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    std::vector<int> actual;

    for (auto value : tree)
    {
        actual.push_back(value);
    }

    ASSERT_EQ(expected, actual);
}

TEST(TestIterator, IteratorCopyValid)
{
    BinarySearchTree<int> tree = create_simple_tree();

    auto it = tree.begin();
    auto it2 = it;
    ASSERT_EQ(*it, *it2);
    ++it;
    ASSERT_NE(*it, *it2);
}

TEST(TestIterator, IteratorFindValid)
{
    BinarySearchTree<int> tree = create_simple_tree();

    auto it = tree.find(8);
    ASSERT_EQ(*it, 8);
    ++it;
    ASSERT_EQ(*it, 10);
    --it;
    ASSERT_EQ(*it, 8);
    it = tree.find(14);
    ASSERT_EQ(*it, 14);
    --it;
    ASSERT_EQ(*it, 13);
    it = tree.find(1);
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 3);
}

struct Point
{
    int x;
    int y;

    // enough for binary search tree
    bool operator<(const Point &other) const
    {
        return x < other.x || (x == other.x && y < other.y);
    }

    // required for assertions
    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point &other) const
    {
        return !(*this == other);
    }
};

TEST(TestCustomType, InsertValid)
{
    BinarySearchTree<Point> tree;
    tree.insert({5, 6});
    tree.insert({7, 8});
    tree.insert({1, 2});
    tree.insert({9, 10});
    tree.insert({3, 4});
    tree.insert({11, 12});

    ASSERT_LT(tree.minimum(), (Point{3, 4}));
    ASSERT_EQ(tree.minimum(), (Point{1, 2}));
    ASSERT_EQ(tree.maximum(), (Point{11, 12}));
    ASSERT_EQ(tree.successor({1, 2}), (Point{3, 4}));
    ASSERT_EQ(tree.successor({3, 4}), (Point{5, 6}));
    ASSERT_EQ(tree.successor({5, 6}), (Point{7, 8}));
    ASSERT_EQ(tree.successor({7, 8}), (Point{9, 10}));
    ASSERT_EQ(tree.successor({9, 10}), (Point{11, 12}));
    ASSERT_FALSE(tree.successor({11, 12}).has_value());
    ASSERT_EQ(tree.predecessor({11, 12}), (Point{9, 10}));
    ASSERT_EQ(tree.predecessor({9, 10}), (Point{7, 8}));
    ASSERT_EQ(tree.predecessor({7, 8}), (Point{5, 6}));
    ASSERT_EQ(tree.predecessor({5, 6}), (Point{3, 4}));
    ASSERT_EQ(tree.predecessor({3, 4}), (Point{1, 2}));
    ASSERT_FALSE(tree.predecessor({1, 2}).has_value());

    ASSERT_EQ(tree.left_child_value({5, 6}), (Point{1, 2}));
    ASSERT_EQ(tree.right_child_value({5, 6}), (Point{7, 8}));
    ASSERT_FALSE(tree.parent_value({5, 6}).has_value());
    ASSERT_FALSE(tree.left_child_value({1, 2}).has_value());
    ASSERT_EQ(tree.right_child_value({1, 2}), (Point{3, 4}));
    ASSERT_EQ(tree.parent_value({1, 2}), (Point{5, 6}));
    ASSERT_FALSE(tree.left_child_value({3, 4}).has_value());
    ASSERT_FALSE(tree.right_child_value({3, 4}).has_value());
    ASSERT_EQ(tree.parent_value({3, 4}), (Point{1, 2}));
    ASSERT_FALSE(tree.left_child_value({7, 8}).has_value());
    ASSERT_EQ(tree.right_child_value({7, 8}), (Point{9, 10}));
    ASSERT_EQ(tree.parent_value({7, 8}), (Point{5, 6}));
    ASSERT_FALSE(tree.left_child_value({9, 10}).has_value());
    ASSERT_EQ(tree.right_child_value({9, 10}), (Point{11, 12}));
    ASSERT_EQ(tree.parent_value({9, 10}), (Point{7, 8}));
    ASSERT_FALSE(tree.left_child_value({11, 12}).has_value());
    ASSERT_FALSE(tree.right_child_value({11, 12}).has_value());
    ASSERT_EQ(tree.parent_value({11, 12}), (Point{9, 10}));
}

TEST(TestCustomType, IteratorValid)
{
    BinarySearchTree<Point> tree;
    tree.insert({5, 6});
    tree.insert({7, 8});
    tree.insert({1, 2});
    tree.insert({9, 10});
    tree.insert({3, 4});
    tree.insert({11, 12});

    std::vector<Point> expected = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}};
    std::vector<Point> actual;

    for (auto it = tree.begin(); it != tree.end(); ++it)
    {
        actual.push_back(*it);
    }

    ASSERT_EQ(expected, actual);
}

struct Point2
{
    int x;
    int y;

    bool operator==(const Point2 &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point2 &other) const
    {
        return !(*this == other);
    }
};

struct PointCompare
{
    bool operator()(const Point2 &a, const Point2 &b) const
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

TEST(TestCustomType, CustomComparatorValid)
{
    BinarySearchTree<Point2, PointCompare> tree;
    tree.insert({5, 6});
    tree.insert({7, 8});
    tree.insert({1, 2});
    tree.insert({9, 10});
    tree.insert({3, 4});
    tree.insert({11, 12});

    ASSERT_EQ(tree.minimum(), (Point2{1, 2}));
    ASSERT_EQ(tree.maximum(), (Point2{11, 12}));
    ASSERT_EQ(tree.successor({1, 2}), (Point2{3, 4}));
    ASSERT_EQ(tree.successor({3, 4}), (Point2{5, 6}));
    ASSERT_EQ(tree.successor({5, 6}), (Point2{7, 8}));
    ASSERT_EQ(tree.successor({7, 8}), (Point2{9, 10}));
    ASSERT_EQ(tree.successor({9, 10}), (Point2{11, 12}));
    ASSERT_FALSE(tree.successor({11, 12}).has_value());
    ASSERT_EQ(tree.predecessor({11, 12}), (Point2{9, 10}));
    ASSERT_EQ(tree.predecessor({9, 10}), (Point2{7, 8}));
    ASSERT_EQ(tree.predecessor({7, 8}), (Point2{5, 6}));
    ASSERT_EQ(tree.predecessor({5, 6}), (Point2{3, 4}));
    ASSERT_EQ(tree.predecessor({3, 4}), (Point2{1, 2}));
    ASSERT_FALSE(tree.predecessor({1, 2}).has_value());

    ASSERT_EQ(tree.left_child_value({5, 6}), (Point2{1, 2}));
    ASSERT_EQ(tree.right_child_value({5, 6}), (Point2{7, 8}));
    ASSERT_FALSE(tree.parent_value({5, 6}).has_value());
    ASSERT_FALSE(tree.left_child_value({1, 2}).has_value());
    ASSERT_EQ(tree.right_child_value({1, 2}), (Point2{3, 4}));
    ASSERT_EQ(tree.parent_value({1, 2}), (Point2{5, 6}));
    ASSERT_FALSE(tree.left_child_value({3, 4}).has_value());
    ASSERT_FALSE(tree.right_child_value({3, 4}).has_value());
    ASSERT_EQ(tree.parent_value({3, 4}), (Point2{1, 2}));
    ASSERT_FALSE(tree.left_child_value({7, 8}).has_value());
    ASSERT_EQ(tree.right_child_value({7, 8}), (Point2{9, 10}));
    ASSERT_EQ(tree.parent_value({7, 8}), (Point2{5, 6}));
    ASSERT_FALSE(tree.left_child_value({9, 10}).has_value());
    ASSERT_EQ(tree.right_child_value({9, 10}), (Point2{11, 12}));
    ASSERT_EQ(tree.parent_value({9, 10}), (Point2{7, 8}));
    ASSERT_FALSE(tree.left_child_value({11, 12}).has_value());
    ASSERT_FALSE(tree.right_child_value({11, 12}).has_value());
    ASSERT_EQ(tree.parent_value({11, 12}), (Point2{9, 10}));
}

TEST(TestCustomType, DeleteValid)
{
    BinarySearchTree<Point> tree;
    tree.insert({5, 6});
    tree.insert({7, 8});
    tree.insert({1, 2});
    tree.insert({9, 10});
    tree.insert({3, 4});
    tree.insert({11, 12});

    ASSERT_TRUE(tree.remove({1, 2}));
    ASSERT_FALSE(tree.has_value({1, 2}));

    ASSERT_EQ(tree.left_child_value({5, 6}), (Point{3, 4}));
    ASSERT_EQ(tree.right_child_value({5, 6}), (Point{7, 8}));
    ASSERT_FALSE(tree.parent_value({5, 6}).has_value());
    ASSERT_FALSE(tree.left_child_value({3, 4}).has_value());
    ASSERT_FALSE(tree.right_child_value({3, 4}).has_value());
    ASSERT_EQ(tree.parent_value({3, 4}), (Point{5, 6}));
    ASSERT_FALSE(tree.left_child_value({7, 8}).has_value());
    ASSERT_EQ(tree.right_child_value({7, 8}), (Point{9, 10}));
    ASSERT_EQ(tree.parent_value({7, 8}), (Point{5, 6}));
    ASSERT_FALSE(tree.left_child_value({9, 10}).has_value());
    ASSERT_EQ(tree.right_child_value({9, 10}), (Point{11, 12}));
    ASSERT_EQ(tree.parent_value({9, 10}), (Point{7, 8}));
    ASSERT_FALSE(tree.left_child_value({11, 12}).has_value());
    ASSERT_FALSE(tree.right_child_value({11, 12}).has_value());
    ASSERT_EQ(tree.parent_value({11, 12}), (Point{9, 10}));
}
