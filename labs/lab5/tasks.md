# Lab 5 Tasks

## 1. Linked lists container

*Files:* [list.h](list.h), [single_linked_list.cpp](single_linked_list.cpp), 

*Questions*
* What the difference between `struct` and `class`?
* What is `const` member method?

1. Create a `List` class interface in the header file.
    * create internal public `struct Node`
    * write declarations of methods from lab 3 and 4
    * decide on visibility of each property/method
    * declare `const` member methods

2. Write implementation of class `List` in a cpp file.

*Questions*
* How does C++ create objects?

3. Write no parameter constructor

*Questions*
* What happens to the memory if `List` object goes out of scope?

4. Write destructor that cleans up the memory
    * for linux users: verify with `valgrind`

*Questions*
* What is semantics of copying `List`?

5. Write copy constructor

6. Write move constructor

7. Write assignment operators.

*Questions*
* How is this class constructed before you implemented constructor?
* What would happen if you assign object to itself?

*Resources*
* [cppinsights](https://cppinsights.io/)
* `valgrind`
* [The rule of three/five/zero](https://en.cppreference.com/w/cpp/language/rule_of_three)

## 2. Make `List` abstract

*Files:* [list.h](list.h), [single_linked_list.cpp](single_linked_list.cpp), [test_list.cpp](test_list.cpp)

1. What to do with `Node`?
    * Where (what file) do you place it?
    * How to adjust the interface of methods using `Node`?

*Questions:*
* How to define abstract methods?

2. Define purely virtual functions and virtual destructor.

3. Adjust single linked list implementation
    * rename it to `SingleLinkedList`
    * inherit publicly from `List`
    * `override` virtual methods from the `List` interface
    * how to adjust constructors?

4. Write function that returns your single linked list implementation in the header file using pointer polymorphism.
    Required declaration:
    ```c++
    List * new_single_linked_list();
    ```

5. Verify your implementation by adjusting the tests from lab3 and convert them to test `List` class.
    * Get rid of `Node *` usage.
    * Create list using `new_single_linked_list`.

*Resources:*
* [virtual destructor](https://en.cppreference.com/w/cpp/language/destructor)
* [public vs. private vs. protected inheritance](https://en.cppreference.com/w/cpp/language/derived_class)


## Homework

*Files:* [list.h](list.h), [doubly_linked_list.cpp](doubly_linked_list.cpp)

1. Create another implementation of `List` interface using underlying member `std::vector` property

2. Adjust the tests to take abstract reference to a `List` as a parameter and test both single linked list and double linked list on the same test suite.

*Questions:*
1. Where is the memory stored?

*References:*
* [TEST_P](http://google.github.io/googletest/reference/testing.html#TEST_P)
