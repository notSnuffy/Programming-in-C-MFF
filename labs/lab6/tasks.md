## 1. Make `List` abstract

*Files:* [list.h](list.h), [single_linked_list.cpp](single_linked_list.cpp), [test_list.cpp](test_list.cpp)

1. What to do with `Node`?
    * Where (what file) do you place it?
    * How to adjust the interface of methods using `Node`?
    * How to define abstract methods?

2. Define the interface using purely virtual functions in [list.h](list.h).

3. Adjust single linked list implementation in [single_linked_list.cpp](single_linked_list.cpp).
    * name a class it to `SingleLinkedList`
    * inherit publicly from `List`
    * `override` virtual methods from the `List` interface
    * don't write constructors/destructors just yet

4. Write function that returns your single linked list implementation in the header file using pointer polymorphism.
    Required declaration:
    ```c++
    List * new_single_linked_list();
    ```

5. Verify your implementation using provided parametrized test suite.
    * What is the difference compared to lab5 tests - are the test less or more precise?
    * Does `Node *` removal hurt the tests?
    
6. What are the options for error handling implementation?
    * What are their pros and cons?

*Resources:*
* [public vs. private vs. protected inheritance](https://en.cppreference.com/w/cpp/language/derived_class)

## 2. Rule of 3/5/0

1. Write no parameter constructor
    * How does C++ create objects?
    * How is this class constructed before you implemented constructor?
    * What is `=default` implementation?
    * What is an `explicit` constructor?
    * What happens to the memory if `List` object goes out of scope?
    * Does it make sense for destructor to be `virtual`?

2. Write destructor that cleans up the memory
    * For Linux users: verify with `valgrind`
    * What is semantics of copying `List`?

3. Write a copy constructor.

4. Write a move constructor.

5. Write assignment operators.
    * What would happen if you assign object to itself?

*Resources*
* [The rule of three/five/zero](https://en.cppreference.com/w/cpp/language/rule_of_three)
* [How compiler implicitly declares constructors for you?](https://safecpp.com/RuleOfDesDeMovA.html)
* [Default constructors](https://en.cppreference.com/w/cpp/language/default_constructor)
* [cppinsights](https://cppinsights.io/)
* [explicit keyword](https://en.cppreference.com/w/cpp/keyword/explicit)
* [virtual destructor](https://en.cppreference.com/w/cpp/language/destructor)
* `valgrind`

## 3. Add another implementation

*Files:* [vector_list.cpp](vector_list.cpp)

1. Create another implementation of `List` interface using underlying member `std::vector` property.

2. Check your implementation using test

*Questions:*
1. Where is the memory of the underlying vector stored?

*References:*
* [std::vector](https://en.cppreference.com/w/cpp/container/vector)
* Already implemented tests - [TEST_P](http://google.github.io/googletest/reference/testing.html#TEST_P)
