# _Documentation_

# Folder: src

This folder contains the implementations of the trees.

## BST.h

## **BinarySearchTree<T, Comparator>**

A binary search tree implementation.

### **Type Parameters**

- `T`: The type of values stored in the tree.
- `Comparator` (default: `std::less<T>`): A function object type that can compare two values of type `T`.

### **Member Types**

- `Node`: the tree's nodes.
- `Iterator`: forward iterator over the tree's values (inorder).
- `ReverseIterator`: reverse iterator over the tree's values (reverse inorder).

### **Private Member Variables**

- `root`: A unique pointer to the root of the tree

### **Private Member Function**

#### `bool is_less_than(const T &a, const T &b, Comparator compare = Comparator{}) const`

Returns `true` if `a` < `b`, `false` otherwise

- `a`: Value of the left operand
- `b`: Value of the right operand
- `compare`: Custom comparator defaultly initialized to `Comparator{}` from the template

#### `bool is_equal(const T &a, const T &b) const`

Returns `true` if `a` == `b`, `false` otherwise

- `a`: Value of the left operand
- `b`: Value of the right operand

#### `Node *return_node_with_value(const T &value) const`

Returns pointer to the node with the given value if the tree contains a node with the specified value, `nullptr` otherwise.

- `value`: The value of the node to return.

### **Public Member Functions**

#### `BinarySearchTree()`

Constructs an empty binary search tree.

#### `BinarySearchTree(BinarySearchTree &&other)`

Construct a new tree from the moved tree `other`.

- `other`: A tree to move

#### `BinarySearchTree &operator=(BinarySearchTree &&other)`

Assigns a new tree from the moved tree `other`.

- `other`: A tree to move

#### `bool has_value(const T &value) const`

Returns `true` if the tree contains a node with the specified value, `false` otherwise.

- `value`: The value to search for.

#### `std::optional<T> left_child_value(const T &value) const`

Returns the value of the left child of the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose left child's value to return.

#### `std::optional<T> right_child_value(const T &value) const`

Returns the value of the right child of the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose right child's value to return.

#### `std::optional<T> parent_value(const T &value) const`

Returns the value of the parent of the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose parent's value to return.

#### `std::optional<T> maximum(const T &value) const`

Returns the maximum value of the subtree whose root is the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose maximum value to return.

#### `std::optional<T> maximum() const`

Returns the maximum value of the tree, if it exists, or an empty `std::optional<T>` otherwise.

#### `std::optional<T> minimum(const T &value) const`

Returns the minimum value of the subtree whose root is the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose minimum value to return.

#### `std::optional<T> minimum() const`

Returns the minimum value of the tree, if it exists, or an empty `std::optional<T>` otherwise.

#### `std::optional<T> successor(const T &value) const`

Returns the value of the successor of the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose successor's value to return.

#### `std::optional<T> predecessor(const T &value) const`

Returns the value of the predecessor of the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose predecessor's value to return.

#### `bool insert(const T &value)`

Inserts a node with the given value into the tree and returns `true`, if successful, or `false` otherwise.

- `value`: The value to be inserted into the tree

#### `bool remove(const T &value)`

Removes a node with the given value from the tree and returns true, if successful, or false otherwise.

- `value`: The value to be deleted from the tree

#### `Iterator begin() const`

Returns iterator to the first node returned by inorder traversal(minimum), if it exists, or invalid iterator otherwise.

#### `Iterator end() const`

Returns invalid iterator representing end.

#### `ReverseIterator rbegin() const`

Returns iterator to the first node returned by reverse inorder traversal(macimum), if it exists, or invalid iterator otherwise.

#### `ReverseIterator end() const`

Returns invalid reverse iterator representing end.

#### `Iterator find(const T& value) const`

Returns iterator to the node with the given value, if it exists, or invalid iterator otherwise.

- `value`: The value of the node whose iterator to return

### `Node`

Struct representing a node in the binary search tree.

#### **Member Variables**

- `value`: The value stored in the node.
- `left`: A unique pointer to the left node, or `nullptr` if the node has no left child.
- `right`: A unique pointer to the right node, or `nullptr` if the node has no right child.
- `parent`: A pointer to the parent node, or `nullptr` if the node has no parent.

#### **Member Functions**

- `Node(const T& value)` - Constructs a node with given value.

### **Iterator Operations**

`BinarySearchTree` provides forward and reverse iterators to traverse its values. You can use these iterators with the standard library algorithms that accept iterators.

#### `Iterator`

A forward iterator over the tree's values (inorder).

##### **Private Member Variables**

- `current`: Pointer to the current node.

##### **Member Types**

- `iterator_category`: The type of the iterator category (bidirectional iterator).
- `value_type`: The type of the value being iterated over (same as `T`).
- `reference`: The type of the reference to the value being iterated over (same as `const T&`).
- `pointer`: The type of the pointer to the value being iterated over (same as `const T*`).
- `difference_type`: The type of the difference between two iterators (same as `std::ptrdiff_t`).

##### **Member Functions**

- `Iterator()`: Constructs an invalid iterator.
- `Iterator(Node *node)`: Constructs an iterator pointing to the specified node.
- `bool operator==(const Iterator &other) const`: Returns `true` if this iterator is equal to `other`, `false` otherwise.
- `bool operator!=(const Iterator &other) const`: Returns `true` if this iterator is not equal to `other`, `false` otherwise.
- `reference operator*() const`: Returns a reference to the value at the iterator's current position.
- `pointer operator->() const`: Returns a pointer to the value at the iterator's current position.
- `Iterator &operator++()`: Advances the iterator to the next value and returns a reference to the updated iterator.
- `Iterator operator++(int)`: Advances the iterator to the next value and returns a copy of the old iterator.
- `Iterator &operator--()`: Retreats the iterator to the previous value and returns a reference to the updated iterator.
- `Iterator operator--(int)`: Retreats the iterator to the previous value and returns a copy of the old iterator.

#### `ReverseIterator`

A reverse iterator over the tree's values.

##### **Member Functions**

- `ReverseIterator()`: Constructs an invalid iterator.
- `ReverseIterator(Node *node)`: Constructs an iterator pointing to the specified node.
- `ReverseIterator &operator++()`: Advances the iterator to the next value and returns a reference to the updated iterator.
- `ReverseIterator &operator--()`: Retreats the iterator to the previous value and returns a reference to the updated iterator.

## AVL.h

## **AVLTree<T, Comparator>**

An AVL tree implementation.

### **Type Parameters**

- `T`: The type of values stored in the tree.
- `Comparator` (default: `std::less<T>`): A function object type that can compare two values of type `T`.

### **Member Types**

- `Node`: the tree's nodes.
- `Iterator`: forward iterator over the tree's values (inorder).
- `ReverseIterator`: reverse iterator over the tree's values (reverse inorder).

### **Private Member Variables**

- `root`: A unique pointer to the root of the tree

### **Private Member Function**

#### `bool is_less_than(const T &a, const T &b, Comparator compare = Comparator{}) const`

Returns `true` if `a` < `b`, `false` otherwise

- `a`: Value of the left operand
- `b`: Value of the right operand
- `compare`: Custom comparator defaultly initialized to `Comparator{}` from the template

#### `bool is_equal(const T &a, const T &b) const`

Returns `true` if `a` == `b`, `false` otherwise

- `a`: Value of the left operand
- `b`: Value of the right operand

#### `Node *return_node_with_value(const T &value) const`

Returns pointer to the node with the given value if the tree contains a node with the specified value, `nullptr` otherwise.

- `value`: The value of the node to return.

#### `int height(const Node *node) const`

Return the height of the given node, `0` otherwise

- `node`: A pointer to the node whose height to return.

#### `void update_height(Node *node)`

Updates height of the given node

- `node`: A pointer to the node whose height to update.

#### `std::unique_ptr<Node> left_rotate(std::unique_ptr<Node> node)`

Returns a unique pointer to the new root of the subtree after left rotation is performed on `node`.

- `node`: A unique pointer to the node that needs to be rotated.

#### `std::unique_ptr<Node> right_rotate(std::unique_ptr<Node> node)`

Returns a unique pointer to the new root of the subtree after right rotation is performed on `node`.

- `node`: A unique pointer to the node that needs to be rotated.

#### `int balance_factor(const Node *node) const`

Return the balance factor of the given node, if it exists, `0` otherwise.

- `node`: A pointer to the node whose balance factor to return.

#### `std::unique_ptr<Node> rebalance(std::unique_ptr<Node> node)`

Rebalances the subtree given by `node` and returns a unique pointer to the new root of the subtree.

- `node`: A unique pointer pointing to the root of the subtree to be rebalanced

#### `std::optional<std::unique_ptr<Node>> _insert(std::unique_ptr<Node> node, const T &value)`

Recursive function that inserts a new node with given value into AVL tree rooted at `node` which returns a unique pointer to the new root, if insertion successful, or an empty `std::optional<T>` otherwise(duplicate value).

- `node`: A unique pointer to the root of the AVL tree/subtree.
- `value`: The value to be inserted into the tree.

#### `std::optional<std::unique_ptr<Node>> _remove(std::unique_ptr<Node> node, const T &value)`

Recursive function that removes a node with given value from AVL tree rooted at `node` which returns a unique pointer to the new root, if removal successful, or an empty `std::optional<T>` otherwise(no such value).

- `node`: A unique pointer to the root of the AVL tree/subtree.
- `value`: The value of the node to be deleted from the tree.

### **Public Member Functions**

#### `AVLTree()`

Constructs an empty AVL tree.

#### `AVLTree(AVLTree &&other)`

Construct a new tree from the moved tree `other`

- `other`: A tree to move.

#### `AVLTree &operator=(AVLTree &&other)`

Assigns a new tree from the moved tree `other`

- `other`: A tree to move.

#### `bool has_value(const T &value) const`

Returns `true` if the tree contains a node with the specified value, `false` otherwise.

- `value`: The value to search for.

#### `std::optional<T> left_child_value(const T &value) const`

Returns the value of the left child of the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose left child's value to return.

#### `std::optional<T> right_child_value(const T &value) const`

Returns the value of the right child of the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose right child's value to return.

#### `std::optional<T> parent_value(const T &value) const`

Returns the value of the parent of the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose parent's value to return.

#### `std::optional<T> maximum(const T &value) const`

Returns the maximum value of the subtree whose root is the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose maximum value to return.

#### `std::optional<T> maximum() const`

Returns the maximum value of the tree, if it exists, or an empty `std::optional<T>` otherwise.

#### `std::optional<T> minimum(const T &value) const`

Returns the minimum value of the subtree whose root is the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose minimum value to return.

#### `std::optional<T> minimum() const`

Returns the minimum value of the tree, if it exists, or an empty `std::optional<T>` otherwise.

#### `std::optional<T> successor(const T &value) const`

Returns the value of the successor of the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose successor's value to return.

#### `std::optional<T> predecessor(const T &value) const`

Returns the value of the predecessor of the node with the specified value, if it exists, or an empty `std::optional<T>` otherwise.

- `value`: The value of the node whose predecessor's value to return.

#### `Iterator begin() const`

Returns iterator to the first node returned by inorder traversal(minimum), if it exists, or invalid iterator otherwise.

#### `Iterator end() const`

Returns invalid iterator representing end.

#### `ReverseIterator rbegin() const`

Returns iterator to the first node returned by reverse inorder traversal(macimum), if it exists, or invalid iterator otherwise.

#### `ReverseIterator end() const`

Returns invalid reverse iterator representing end.

#### `Iterator find(const T& value) const`

Returns iterator to the node with the given value, if it exists, or invalid iterator otherwise.

- `value`: The value of the node whose iterator to return

#### `bool insert(const T &value)`

Inserts a node with the given value into the tree and returns `true`, if successful, or `false` otherwise.

- `value`: The value to be inserted into the tree

#### `bool remove(const T &value)`

Removes a node with the given value from the tree and returns true, if successful, or false otherwise.

- `value`: The value to be deleted from the tree

### `Node`

Struct representing a node in the AVL tree.

#### **Member Variables**

- `value`: The value stored in the node.
- `left`: A unique pointer to the left node, or `nullptr` if the node has no left child.
- `right`: A unique pointer to the right node, or `nullptr` if the node has no right child.
- `parent`: A pointer to the parent node, or `nullptr` if the node has no parent.
- `height`: An integer representing height of the subtree rooted at node.

#### **Member Functions**

- `Node(const T& value)` - Constructs a node with given value.

### **Iterator Operations**

`AVLTree` provides forward and reverse iterators to traverse its values. You can use these iterators with the standard library algorithms that accept iterators.

#### `Iterator`

A forward iterator over the tree's values (inorder).

##### **Private Member Variables**

- `current`: Pointer to the current node.

##### **Member Types**

- `iterator_category`: The type of the iterator category (bidirectional iterator).
- `value_type`: The type of the value being iterated over (same as `T`).
- `reference`: The type of the reference to the value being iterated over (same as `const T&`).
- `pointer`: The type of the pointer to the value being iterated over (same as `const T*`).
- `difference_type`: The type of the difference between two iterators (same as `std::ptrdiff_t`).

##### **Member Functions**

- `Iterator()`: Constructs an invalid iterator.
- `Iterator(Node *node)`: Constructs an iterator pointing to the specified node.
- `bool operator==(const Iterator &other) const`: Returns `true` if this iterator is equal to `other`, `false` otherwise.
- `bool operator!=(const Iterator &other) const`: Returns `true` if this iterator is not equal to `other`, `false` otherwise.
- `reference operator*() const`: Returns a reference to the value at the iterator's current position.
- `pointer operator->() const`: Returns a pointer to the value at the iterator's current position.
- `Iterator &operator++()`: Advances the iterator to the next value and returns a reference to the updated iterator.
- `Iterator operator++(int)`: Advances the iterator to the next value and returns a copy of the old iterator.
- `Iterator &operator--()`: Retreats the iterator to the previous value and returns a reference to the updated iterator.
- `Iterator operator--(int)`: Retreats the iterator to the previous value and returns a copy of the old iterator.

#### `ReverseIterator`

A reverse iterator over the tree's values.

##### **Member Functions**

- `ReverseIterator()`: Constructs an invalid iterator.
- `ReverseIterator(Node *node)`: Constructs an iterator pointing to the specified node.
- `ReverseIterator &operator++()`: Advances the iterator to the next value and returns a reference to the updated iterator.
- `ReverseIterator &operator--()`: Retreats the iterator to the previous value and returns a reference to the updated iterator.

# Folder: demo

This folder contains the demo program using the implemented trees.

## demo.cpp

## **subsequence_exists<Tree>**

### **Template Parameters**

- `Tree`: A templated tree.

### **Function Parameters**

- `tree`: A tree where to search for the given sequence.
- `sequence`: A vector of integers representing the subsequence to search for in the tree.

### **Return Value**

Returns `true` if the sequence exists in the tree, `false` otherwise.

# Folder: comparer

This folder contains the class to compare trees.

## tree_comparer.h

## **TreeCompareer<MyTree, ComparedTree, nodes>**

The `TreeComparer` class is a templated class that allows comparison of two trees. It has three member functions, each comparing a different aspect of the trees: insertion duration, value existence duration, and removal duration.

### Type Parameters

- `MyTree`: The first tree to compare.
- `ComparedTree`: The second tree to compare.
- `nodes`: The number of nodes in each tree.

### Private Member Functions

- `double compare_insert_duration(Tree &tree)`: Helper function for `compare_insert` that returns the duration of inserting each value in the shuffled `data` vector into `tree`.
- `void compare_insert(MyTree &my_tree, ComparedTree &compared_tree)`: Compares the duration of inserting each value in the shuffled `data` vector into `my_tree` and `compared_tree`.
- `double compare_has_value_duration(Tree &tree)`: Helper function for `compare_has_value` that returns the duration of checking for the existence of each value in the shuffled `data` vector in `tree`.
- `void compare_has_value(MyTree &my_tree, ComparedTree &compared_tree)`: Compares the duration of checking for the existence of each value in the shuffled `data` vector in `my_tree` and `compared_tree`.
- `double compare_remove_duration(Tree &tree)`: Helper function for `compare_remove` that returns the duration of removing each value in the shuffled `data` vector from `tree`.
- `void compare_remove(MyTree &my_tree, ComparedTree &compared_tree)`: Compares the duration of removing each value in the shuffled `data` vector from `my_tree` and `compared_tree`.

### Public Member Functions

- `TreeComparer()`: Constructs an instance of `TreeComparer` and initializes the `data` vector with values from 1 to `nodes`, which are then shuffled randomly.
- `void run()`: Runs all the comparisons of the durations.

### Private Member Variables

- `data`: A vector containing values from 1 to `nodes` that are shuffled randomly.

## compare.cpp

File that contains the main function for the comparisons.

## compared_trees

Folder that contains the implementations of the trees to be compared.
