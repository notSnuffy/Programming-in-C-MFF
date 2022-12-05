# Lab A - Iterators and algorithms

## 0. Git lab/hub development workflow

1. Showcase of merge request workflows
    * how to submit merge request change
    * branch protection
    * review and approval process
    * continuous integration
    * how to merge a merge-request, what is rebase and squash?

2. Fork workflow

## 1. Container iterator and templates (rollover)
*Files:* [iterators.cpp](./iterators.cpp)

1. Write a simple loop that reads characters from `std::cin` and stores their histogram in `map<char, int>`, then print this using
    * `std::pair<char, int>` and its properties `.first` and `.seconds`
    * Use structural bindings.

2. Write a set of a custom type `std::set<S>`
    * What operator needs to be overloaded on `S`?

*Reference:*
* [cppreference: `std::set`](https://en.cppreference.com/w/cpp/container/set)
* [cppreference: `std::map`](https://en.cppreference.com/w/cpp/container/map)
* [cppreference: structural bindings](https://en.cppreference.com/w/cpp/language/structured_binding)

## 2. Functors
*Files:* [functors.cpp](./functors.cpp)

1. Create an unordered map with your custom key
    * What does compiler miss on compilation?
    * What are the template parameters of the `std::unordered_map`?
    * How to implement hash and equal functions?
        1. overload in-class operator
        2. create dedicated functor class
        3. create template specializations for `std::hash<S>` and `std::equal_to<S>`

2. Insert elements into map using 3 different ways
    * What is the inner type?
    * Use structural binding syntax for return value of `std::map<K, V>::insert`.

*Reference:*
* [cppreference: `std::unordered_map`](https://en.cppreference.com/w/cpp/container/unordered_map)
* [cppreference: structural bindings](https://en.cppreference.com/w/cpp/language/structured_binding)

## 3. Algorithms
*Files:* [algorithms.cpp](./algorithms.cpp)

0. Skim through [cppreference: Algorithms library](https://en.cppreference.com/w/cpp/algorithm) and go see all kinds of "algorithms" it has to offer.
    * What functions are used in algorithms?
    ```c++
    // Unary predicate
    bool pred(const Type1 &a);
    // Binary predicate
    bool pred(const Type1 &a, const Type2 &b);
    // Unary function
    void fun(const Type &a);
    // Comparator
    bool cmp(const Type1 &a, const Type2 &b);
    // Usage with &
    algorithm(begin, end, &pred);
    ```

1. Find min/max of a vector
    * try custom comparator (e.g. for a scenario of vector of your own structures - `Person` find min `Person::age`)

2. Find an element of a vector
    * Find an element of a vector matching a predicate (e.g. `is_even`)

3. Get a sum and product of a vector

4. Get unique elements of a vector
    * remember to erase the duplicates

5. Set second half of a vector to `-1`
    * use "pointer arithmetics" on iterators

6. Try out different containers other than vector with some algorithms
    * sets, maps, their unordered variants, arrays...

7. Look into some more interesting algorithms:
    * Query containers: `find`, `find_if`, `count`, `count_if`, `lower_bound`, `upper_bound`
    * Update containers: `fill`, `for_each`, `sort`, `transform`, `remove`, `remove_if`, `unique` (mind actual destruction), `erase`
    * Create containers: `copy`, `copy_if`
    * These are just hand-picked, exhaustive list is at cppreference.

*Reference:*
* [cppreference: Algorithms library](https://en.cppreference.com/w/cpp/algorithm)
