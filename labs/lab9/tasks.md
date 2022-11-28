# Lab 9 - Containers and iterators

## 1. Operator overloading and casts
*Files:* [overloading.cpp](./overloading.cpp), [const_cast.cpp](./const_cast.cpp)

1. Look at reference and implement following operators for class `Coordinates`
    * one arithmetic operator to overload
    * one comparison operator
    * output `operator<<`
    * `operator[]` or `operator()`
    * `operator "" <suffix-identifier>`

2. Special type of operators are conversion operators they enable conversion from one type to another - implement conversion operator to `std::string`.

3. *Question:* What is the difference between
    * `static_cast`
    * `dynamic_cast`
    * `const_cast`
    * `reinterpret_cast`
    * c-style cast

4. Try out what does `const_cast` do in [const_cast.cpp](./const_cast.cpp).

*Questions:*
* Is operator overloading a good idea? Overall, it is just another name for a function right?

*Reference:*
* [cppreference: Operator overloading](https://en.cppreference.com/w/cpp/language/operators)
* [cppreference: Expressions](https://en.cppreference.com/w/cpp/language/expressions)
* [cppreference: Explicit type casts](https://en.cppreference.com/w/cpp/language/explicit_cast)

## 2. Container iterator and templates
*Files:* [iterators.cpp](./iterators.cpp)

0. *Questions:* What does `for (auto x : c)` translate to?

1. Implement non-templated `print` function.

2. Implement non-templated `bubblesort` function to sort vector inplace.
    * *hint* use `std::swap` to do the inplace swap

3. Write a templated function `print` to print `vector<floats>` as well as `set<int>`
    * try and print `vector<int>` which function would be called?

4. Write a templated function `bubblesort` to sort `vector<int>` as well as `vector<float>`

5. Write a simple loop that reads characters from `std::cin` and stores their histogram in `map<char, int>`, then print this using
    * `std::pair<char, int>` and its properties `.first` and `.seconds`
    * structural bindings 

6. Write a set of a custom type `std::set<S>`
    * What operator needs to be overloaded on `S`?

*Reference:*
* [cppreference: `std::vector` -> Member types -> `iterator`](https://en.cppreference.com/w/cpp/container/vector)
* [cppreference: `std::set`](https://en.cppreference.com/w/cpp/container/set)
* [cppreference: `std::map`](https://en.cppreference.com/w/cpp/container/map)
* [cppreference: structural bindings](https://en.cppreference.com/w/cpp/language/structured_binding)
