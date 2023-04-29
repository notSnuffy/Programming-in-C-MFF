#include <AVL.h>
#include <gtest/gtest.h>
#include <numeric>

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

template <typename T>
bool isNodeCorrect(const AVLTree<T> &tree, const T &node, const T &parent, const T &left, const T &right)
{
    if (tree.parent_value(node).value_or(-1) != parent && tree.left_child_value(node).value_or(-1) != left && tree.right_child_value(node).value_or(-1) != right)
    {
        return false;
    }
    return true;
}

TEST(TestInsert, RootNodeValid)
{

    AVLTree<int> tree;

    ASSERT_TRUE(tree.insert(10));
}

TEST(TestInsert, LeftLeafNodeValid)
{
    AVLTree<int> tree;
    tree.insert(10);
    ASSERT_TRUE(tree.insert(8));
}

TEST(TestInsert, RightLeafNodeValid)
{
    AVLTree<int> tree;
    tree.insert(10);
    ASSERT_TRUE(tree.insert(8));
}

TEST(TestInsert, DeeplyNestedTreeValid)
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

TEST(TestInsert, DeeplyNestedTreeInvalid)
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

TEST(TestInsert, SmallTreeInsert15Valid)
{
    AVLTree<int> tree;
    tree.insert(20);
    tree.insert(4);
    tree.insert(15);

    ASSERT_TRUE(isNodeCorrect(tree, 15, -1, 4, 20));
    ASSERT_TRUE(isNodeCorrect(tree, 4, 15, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 20, 15, -1, -1));
}

TEST(TestInsert, MiddleTreeInsert15Valid)
{
    AVLTree<int> tree;
    tree.insert(20);
    tree.insert(4);
    tree.insert(3);
    tree.insert(9);
    tree.insert(26);
    tree.insert(15);

    ASSERT_TRUE(isNodeCorrect(tree, 9, -1, 4, 20));
    ASSERT_TRUE(isNodeCorrect(tree, 4, 9, 3, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 3, 4, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 20, 9, 15, 26));
    ASSERT_TRUE(isNodeCorrect(tree, 15, 20, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 26, 20, -1, -1));
}

TEST(TestInsert, BigTreeInsert15Valid)
{
    AVLTree<int> tree;
    tree.insert(20);
    tree.insert(4);
    tree.insert(3);
    tree.insert(9);
    tree.insert(2);
    tree.insert(7);
    tree.insert(11);
    tree.insert(26);
    tree.insert(21);
    tree.insert(30);
    tree.insert(15);

    ASSERT_TRUE(isNodeCorrect(tree, 9, -1, 4, 20));
    ASSERT_TRUE(isNodeCorrect(tree, 4, 9, 3, 7));
    ASSERT_TRUE(isNodeCorrect(tree, 3, 4, 2, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 2, 3, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 7, 4, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 20, 9, 11, 26));
    ASSERT_TRUE(isNodeCorrect(tree, 11, 20, -1, 15));
    ASSERT_TRUE(isNodeCorrect(tree, 15, 11, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 26, 20, 21, 30));
    ASSERT_TRUE(isNodeCorrect(tree, 21, 26, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 30, 26, -1, -1));
}

TEST(TestInsert, SmallTreeInsert8Valid)
{
    AVLTree<int> tree;
    tree.insert(20);
    tree.insert(4);
    tree.insert(8);

    ASSERT_TRUE(isNodeCorrect(tree, 8, -1, 4, 20));
    ASSERT_TRUE(isNodeCorrect(tree, 4, 8, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 20, 8, -1, -1));
}

TEST(TestInsert, MiddleTreeInsert8Valid)
{
    AVLTree<int> tree;
    tree.insert(20);
    tree.insert(4);
    tree.insert(3);
    tree.insert(9);
    tree.insert(26);
    tree.insert(8);

    ASSERT_TRUE(isNodeCorrect(tree, 9, -1, 4, 20));
    ASSERT_TRUE(isNodeCorrect(tree, 4, 9, 3, 8));
    ASSERT_TRUE(isNodeCorrect(tree, 3, 4, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 8, 4, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 20, 9, -1, 26));
    ASSERT_TRUE(isNodeCorrect(tree, 26, 20, -1, -1));
}

TEST(TestInsert, BigTreeInsert8Valid)
{
    AVLTree<int> tree;
    tree.insert(20);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(9);
    tree.insert(7);
    tree.insert(11);
    tree.insert(26);
    tree.insert(21);
    tree.insert(30);
    tree.insert(8);

    ASSERT_TRUE(isNodeCorrect(tree, 9, -1, 4, 20));
    ASSERT_TRUE(isNodeCorrect(tree, 4, 9, 3, 7));
    ASSERT_TRUE(isNodeCorrect(tree, 3, 4, 2, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 2, 3, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 7, 4, -1, 8));
    ASSERT_TRUE(isNodeCorrect(tree, 8, 7, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 20, 9, 11, 26));
    ASSERT_TRUE(isNodeCorrect(tree, 11, 20, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 26, 20, 21, 30));
    ASSERT_TRUE(isNodeCorrect(tree, 21, 26, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 30, 26, -1, -1));
}

TEST(TestRemove, NoNodeInvalid)
{
    AVLTree<int> tree = create_simple_tree();
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
    AVLTree<int> tree;
    tree.insert(10);
    ASSERT_TRUE(tree.has_value(10));
    ASSERT_TRUE(tree.remove(10));
    ASSERT_FALSE(tree.has_value(10));
    ASSERT_FALSE(tree.maximum());
}

TEST(TestRemove, LeftRotationValid)
{
    AVLTree<int> tree;
    tree.insert(1);
    tree.insert(0);
    tree.insert(2);
    tree.insert(3);
    ASSERT_TRUE(tree.remove(0));

    ASSERT_TRUE(isNodeCorrect(tree, 2, -1, 1, 3));
    ASSERT_TRUE(isNodeCorrect(tree, 1, 2, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 3, 2, -1, -1));
}

TEST(TestRemove, RightRotationValid)
{
    AVLTree<int> tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(0);
    tree.insert(3);
    ASSERT_TRUE(tree.remove(3));

    ASSERT_TRUE(isNodeCorrect(tree, 1, -1, 0, 2));
    ASSERT_TRUE(isNodeCorrect(tree, 0, 1, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 2, 1, -1, -1));
}

TEST(TestRemove, RightLeftRotationValid)
{
    AVLTree<int> tree;
    tree.insert(1);
    tree.insert(0);
    tree.insert(3);
    tree.insert(2);
    ASSERT_TRUE(tree.remove(0));

    ASSERT_TRUE(isNodeCorrect(tree, 2, -1, 1, 3));
    ASSERT_TRUE(isNodeCorrect(tree, 1, 2, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 3, 2, -1, -1));
}

TEST(TestRemove, LeftRightRotationValid)
{
    AVLTree<int> tree;
    tree.insert(2);
    tree.insert(0);
    tree.insert(1);
    tree.insert(3);
    ASSERT_TRUE(tree.remove(3));

    ASSERT_TRUE(isNodeCorrect(tree, 1, -1, 0, 2));
    ASSERT_TRUE(isNodeCorrect(tree, 0, 1, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 2, 1, -1, -1));
}

TEST(TestRemove, SmallTreeValid)
{
    AVLTree<int> tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(4);
    tree.insert(3);
    tree.insert(5);
    ASSERT_TRUE(tree.remove(1));

    ASSERT_TRUE(isNodeCorrect(tree, 4, -1, 2, 5));
    ASSERT_TRUE(isNodeCorrect(tree, 2, 4, -1, 3));
    ASSERT_TRUE(isNodeCorrect(tree, 3, 2, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 5, 4, -1, -1));
}

TEST(TestRemove, BigTree1Valid)
{
    AVLTree<int> tree;
    tree.insert(6);
    tree.insert(2);
    tree.insert(9);
    tree.insert(1);
    tree.insert(4);
    tree.insert(8);
    tree.insert(10);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    ASSERT_TRUE(tree.remove(1));

    ASSERT_TRUE(isNodeCorrect(tree, 6, -1, 4, 9));
    ASSERT_TRUE(isNodeCorrect(tree, 4, 6, 2, 5));
    ASSERT_TRUE(isNodeCorrect(tree, 2, 4, -1, 3));
    ASSERT_TRUE(isNodeCorrect(tree, 3, 2, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 5, 4, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 9, 6, 8, 10));
    ASSERT_TRUE(isNodeCorrect(tree, 8, 9, 7, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 7, 8, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 10, 9, -1, -1));
}

TEST(TestRemove, BigTree2Valid)
{
    AVLTree<int> tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(8);
    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(10);
    tree.insert(4);
    tree.insert(6);
    tree.insert(9);
    tree.insert(11);
    tree.insert(12);
    ASSERT_TRUE(tree.remove(1));

    ASSERT_TRUE(isNodeCorrect(tree, 8, -1, 5, 10));
    ASSERT_TRUE(isNodeCorrect(tree, 5, 8, 3, 7));
    ASSERT_TRUE(isNodeCorrect(tree, 3, 5, 2, 4));
    ASSERT_TRUE(isNodeCorrect(tree, 2, 3, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 4, 3, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 7, 5, 6, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 6, 7, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 10, 8, 9, 11));
    ASSERT_TRUE(isNodeCorrect(tree, 9, 10, -1, -1));
    ASSERT_TRUE(isNodeCorrect(tree, 11, 10, -1, 12));
    ASSERT_TRUE(isNodeCorrect(tree, 12, 11, -1, -1));
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

TEST(TestIterator, IteratorForwardValid)
{
    AVLTree<int> tree = create_simple_tree();

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
    AVLTree<int> tree = create_simple_tree();

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
    AVLTree<int> tree = create_simple_tree();

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
    AVLTree<int> tree = create_simple_tree();

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
    AVLTree<int> tree = create_simple_tree();

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
    AVLTree<int> tree = create_simple_tree();

    auto it = tree.begin();
    auto it2 = it;
    ASSERT_EQ(*it, *it2);
    ++it;
    ASSERT_NE(*it, *it2);
}

TEST(TestIterator, IteratorFindValid)
{
    AVLTree<int> tree = create_simple_tree();

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
    AVLTree<Point> tree;
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
    ASSERT_EQ(tree.right_child_value({5, 6}), (Point{9, 10}));
    ASSERT_FALSE(tree.parent_value({5, 6}).has_value());
    ASSERT_FALSE(tree.left_child_value({1, 2}).has_value());
    ASSERT_EQ(tree.right_child_value({1, 2}), (Point{3, 4}));
    ASSERT_EQ(tree.parent_value({1, 2}), (Point{5, 6}));
    ASSERT_FALSE(tree.left_child_value({3, 4}).has_value());
    ASSERT_FALSE(tree.right_child_value({3, 4}).has_value());
    ASSERT_EQ(tree.parent_value({3, 4}), (Point{1, 2}));
    ASSERT_FALSE(tree.left_child_value({7, 8}).has_value());
    ASSERT_FALSE(tree.right_child_value({7, 8}).has_value());
    ASSERT_EQ(tree.parent_value({7, 8}), (Point{9, 10}));
    ASSERT_EQ(tree.left_child_value({9, 10}), (Point{7, 8}));
    ASSERT_EQ(tree.right_child_value({9, 10}), (Point{11, 12}));
    ASSERT_EQ(tree.parent_value({9, 10}), (Point{5, 6}));
    ASSERT_FALSE(tree.left_child_value({11, 12}).has_value());
    ASSERT_FALSE(tree.right_child_value({11, 12}).has_value());
    ASSERT_EQ(tree.parent_value({11, 12}), (Point{9, 10}));
}

TEST(TestCustomType, IteratorValid)
{
    AVLTree<Point> tree;
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
    AVLTree<Point2, PointCompare> tree;
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
    ASSERT_EQ(tree.right_child_value({5, 6}), (Point2{9, 10}));
    ASSERT_FALSE(tree.parent_value({5, 6}).has_value());
    ASSERT_FALSE(tree.left_child_value({1, 2}).has_value());
    ASSERT_EQ(tree.right_child_value({1, 2}), (Point2{3, 4}));
    ASSERT_EQ(tree.parent_value({1, 2}), (Point2{5, 6}));
    ASSERT_FALSE(tree.left_child_value({3, 4}).has_value());
    ASSERT_FALSE(tree.right_child_value({3, 4}).has_value());
    ASSERT_EQ(tree.parent_value({3, 4}), (Point2{1, 2}));
    ASSERT_FALSE(tree.left_child_value({7, 8}).has_value());
    ASSERT_FALSE(tree.right_child_value({7, 8}).has_value());
    ASSERT_EQ(tree.parent_value({7, 8}), (Point2{9, 10}));
    ASSERT_EQ(tree.left_child_value({9, 10}), (Point2{7, 8}));
    ASSERT_EQ(tree.right_child_value({9, 10}), (Point2{11, 12}));
    ASSERT_EQ(tree.parent_value({9, 10}), (Point2{5, 6}));
    ASSERT_FALSE(tree.left_child_value({11, 12}).has_value());
    ASSERT_FALSE(tree.right_child_value({11, 12}).has_value());
    ASSERT_EQ(tree.parent_value({11, 12}), (Point2{9, 10}));
}

TEST(TestCustomType, DeleteValid)
{
    AVLTree<Point> tree;
    tree.insert({5, 6});
    tree.insert({7, 8});
    tree.insert({1, 2});
    tree.insert({9, 10});
    tree.insert({3, 4});
    tree.insert({11, 12});

    ASSERT_TRUE(tree.remove({1, 2}));
    ASSERT_FALSE(tree.has_value({1, 2}));

    ASSERT_EQ(tree.left_child_value({5, 6}), (Point{3, 4}));
    ASSERT_EQ(tree.right_child_value({5, 6}), (Point{9, 10}));
    ASSERT_FALSE(tree.parent_value({5, 6}).has_value());
    ASSERT_FALSE(tree.left_child_value({3, 4}).has_value());
    ASSERT_FALSE(tree.right_child_value({3, 4}).has_value());
    ASSERT_EQ(tree.parent_value({3, 4}), (Point{5, 6}));
    ASSERT_FALSE(tree.left_child_value({7, 8}).has_value());
    ASSERT_FALSE(tree.right_child_value({7, 8}).has_value());
    ASSERT_EQ(tree.parent_value({7, 8}), (Point{9, 10}));
    ASSERT_EQ(tree.left_child_value({9, 10}), (Point{7, 8}));
    ASSERT_EQ(tree.right_child_value({9, 10}), (Point{11, 12}));
    ASSERT_EQ(tree.parent_value({9, 10}), (Point{5, 6}));
    ASSERT_FALSE(tree.left_child_value({11, 12}).has_value());
    ASSERT_FALSE(tree.right_child_value({11, 12}).has_value());
    ASSERT_EQ(tree.parent_value({11, 12}), (Point{9, 10}));
}
