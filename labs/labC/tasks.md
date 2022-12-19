# Lab C - Clones

**Goal:**
Explore how to make polymorphic copies.
That is, given pointer to base class how to make copy what it is pointing to?

## 1. Clones
*Files:* [clones.cpp](./clones.cpp)

1. Create a vector of pointers to Base and populate it with multiple As and Bs.

2. Try to make a copy, what is the complaint of the compiler?

3. Implement a clone operation on A and B and clone the vector.
    * What std algorithm could you use to implement the clone for the whole vector of unique pointers?

4. Uncomment define of `TASK_4` and create a clone operation for `struct C` - a recursive tree-like structure.

*References:*
* design patterns utilizing clones - prototype, generator
* forward declaration - [stackoverflow](https://stackoverflow.com/questions/553682/when-can-i-use-a-forward-declaration), [cppreference](https://en.cppreference.com/w/cpp/language/class)

*Hints:*
* Try `std::for_each` + `std::back_inserter`
* Don't forget to add forward declarations for both `struct C` and `operator<<`.

## Plan for last lab
* `labD` (2.1.2023)
    * homework review
    * exam tips
    * introduction to *template meta-programming*.
