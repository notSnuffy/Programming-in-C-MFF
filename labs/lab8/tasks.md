# Lab 8 - Using `<memory>` and basic `std` containers

## 1. Say farewell to `new`+`delete`, welcome `std::unique_ptr` and `std::shared_ptr`
*Files:* [memory.cpp](./memory.cpp)

1. Copy file to a system with `valgrind` or other memory check tool available.

2. Resolve all memory leaks without using `delete` - use `std::unique_ptr` and `std::shared_ptr` instead.

3. Look at the last code block and try to reason about what is happening.

## 2. Last quick return to linked list
1. What could Move/Copy mean for the `List` class?
    * What would happen if list is assigned/move constructed to/form itself?

2. Test suite of provided code should be passing
    * Run `valgrind` on it to verify that it leaks memory (unless you implemented proper destructor and erase).

3. Use `std::shared_ptr` to resolve memory leaks.
    * What about using `std::unique_ptr` what issues would you expect?

## 3. Intro to `std::string`, `std::string_view`, `std::vector` and `std::map` aka histogram
*Files:* [histogram.h](./histogram.h), [histogram.cpp](./histogram.cpp), [test_histogram.cpp](./test_histogram.cpp)

0. Why use `std::size_t`?

1. Create histogram of input characters reading chars from standard input, store them in `std::vector`.
    * Write implementation directly to the header file.
        * What is the purpose of the `process` method?
        * How do you prepare the `vector`?
    * Try it out in source files' `main` function.
    * Properly test it in test file.
        * Write your own test based on the example test.
    * Why is `Histogram::input` a reference? Try making it not a reference.

2. Store the histogram in `std::map` vs. `std::unordered_map`.
    * What are the advantages / disadvantages compared to `std::vector`?

3. Compute histogram of word lengths, read strings using `std::istream::operator>><std::string>`.
    * Ignore whitespace characters.

4. Compute histogram of line lengths `std::getline` and parse words from the string.
    * Make sure you do not copy strings as it can be expensive operation, look into `std::string_view` instead.

*Resources:*
* [std::size_t](https://en.cppreference.com/w/cpp/types/size_t)
* [basic_string and basic_string_view](https://en.cppreference.com/w/cpp/string)
* [std::string](https://en.cppreference.com/w/cpp/string/basic_string)
* [std::string_view](https://en.cppreference.com/w/cpp/string/basic_string_view)
* [std::istream](https://en.cppreference.com/w/cpp/io/basic_istream)
* [std::getline](https://en.cppreference.com/w/cpp/string/basic_string/getline)
