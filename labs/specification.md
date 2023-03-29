# *Binary Search Trees*


**Author:** *Holub Lukáš*

**Type:** *Library*

**Target Platform:** *Windows / Linux / Mac / embedded / ...*

**Perceived difficulty:** *5-7*

*Short description and motivation*

## User interface
*Programmers who need a search tree data structrute*

### Library
```c++
class Search Tree
    function traverse;
    function insert;
    function delete;
    function find - maybe minimum, maximum, specific key;
```

> It would be nicer if you were to accomodate this within C++ algorithms infrastructure i.e. provide some interators that are appropriate for given type of binary tree.
I guess I could try to implement an iterator instead of the traversal method. Maybe a bidirectional iterator that traverses inorder, but I am not sure how to really implement it since the interface requires dereference so if user changed the value how can I preserve the tree invariant or should I just implement the iterator using const values?

## Architecture

*templated class in header files for BST, AVL*


## Development & Testing
**Build system:** *CMake*

**Testing Framework:** *GoogleTest*

**Required libraries/frameworks:** *STD*

*Test if basic operations work correctly eventhough it is a bit difficult in graph-like data structures*

> Do you want to try some performance tests as well and compare your implementation with some existing one?
I can try some performance tests eventhough I have never done them before. Would I use the chrono header or should I try to learn the google benchmark library.
I can also try to find some other implementations of the trees and compare it with mine. Would finding implementations in other languages also count?

## Acceptance criteria


**Minimum Viable Product:*Basic operations for said trees and comparison test*

**Extensions:*Maybe print function or some visualisation*
