## 1. Memory faults
*Files*: [memory_faults.cpp](./memory_faults.cpp)

1. Check out different memory faults and figure out how can different tools help you prevent them?
    * What mistakes does compiler prevent?

2. Go on Linux system (e.g. `<sis_login>@u-pl7.ms.mff.cuni.cz`) and run these memory faults with program (possibly just copy and compile the file) with `valgrind`.
    * What mistakes does `valgrind` catch?

## 2. Constructors
*Files*: [test_ctor.cpp](./test_ctor.cpp)

1. When are (Rule of 5) constructors called?
    * complete `TestCtorCount` tests

2. Why virtual destructor?
    * complete `TestDestructorCounter` tests
    * how does it change when you make base class destructor `virtual`?

3. *Homework* Read about [how compiler implicitly declares constructors for you?](https://safecpp.com/RuleOfDesDeMovA.html)
    * impact of member variables on defaulted constructor types.
        * if a class has move only member can it be copied?
        * if a class has copy only member can it be moved?
    * `=delete` and `=default` vs. making copy ctor private
    * `=delete` or `=default` counts as user declaration -> prevents other constructors from being defaulted
    * move only objects
    * if you write initialization constructor does it break rule of 0?
    * for RAII specifics go to task 4
        
4. *Homework* Watch [cppcon: Back to basics: RAII and the Rule of Zero](https://www.youtube.com/watch?v=7Qgd9B1KuMQ&ab_channel=CppCon)
    * helps you understand next topic of smart pointers

*Resources*
* [virtual destructor](https://en.cppreference.com/w/cpp/language/destructor)

## 3. Rule of 3/5/0 (continued from before)
*Files*: from `lab6`

1. What could Move/Copy mean for the `List` class?

2. Write Move/Copy constructors

3. Write Move/Copy assignment operator
    * What would happen if you assign object to itself?

*Takeaway*
* writing Rule of 5 is hard!
* it requires understanding of exception safety (`noexcept`) and resource management
* for that reason C++ standard library implemented most RAII objects for you!

*Resources*
* [The rule of three/five/zero](https://en.cppreference.com/w/cpp/language/rule_of_three)
* [How compiler implicitly declares constructors for you?](https://safecpp.com/RuleOfDesDeMovA.html)
* [Default constructors](https://en.cppreference.com/w/cpp/language/default_constructor)
* [`explicit` keyword for single parameter initialization constructors](https://en.cppreference.com/w/cpp/keyword/explicit)

## 4. Add another implementation
*Files:* from `lab6` [vector_list.cpp](../lab6/vector_list.cpp)

1. Create another implementation of `List` interface using underlying member `std::vector` property.

2. Check your implementation using test suite in `lab6`.

*Questions:*
1. Where is the memory of the underlying vector stored?

*References:*
* [std::vector](https://en.cppreference.com/w/cpp/container/vector)
* Already implemented tests - [TEST_P](http://google.github.io/googletest/reference/testing.html#TEST_P)
