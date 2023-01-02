# Lab D - Templates

**Goal:**
Explore templates and try a bit of template meta-programming.
This is *not* necessary for the exam however advanced C++ course used to have one assignment on template meta-programming, so this is mild introduction.

## 0. Homework 1 recap
* Use some code formatting and be consistent.

* Don't use `std::exit` prefer error code or your own exception handling - `return 0` is sometimes required by Recodex such as in HW2.

* Don't store information you don't need e.g. if you already parsed string into ints don't keep string around.

* Don't parse strings repeatedly!
    * Ideally create tokenizer that returns something like `std::string_view` and parse numbers and operators into your own structure

* Solutions:
    1. `std::stack<int>`
        * encode operators as some special values (negative, `uint64_t` extremes...)
    2. `std::stack<Expression>`
        * use `enum struct` to distinguish operators
    3. `std::stack<PolymorphicExpression>`
        * polymorphism vs. composition idiom
    4. `std::unique_ptr<Expression>`
        * complete binary expression tree was not necessary since you already have it in postfix expression

## 1. Basic template usage
*Files*: [templates.cpp](./templates.cpp)

1. Explore how different types of templates:
    * function templates
    * class templates
    * method templates - and how to define them outside the class
    * template specialization

2. Copy this code to [cppinsights.io](https://cppinsights.io/) and it shows you what templates are instantiated and how.

*Questions*
1. What is template instantiation?
2. When are templates instantiated?
    * What does it mean for template code in libraries? (Where should you write template code to `.cpp` or `.h` files?)

*References:*
* [cppcon: Back to Basics Templates (part 1)](https://www.youtube.com/watch?v=VNJ4wiuxJM4&ab_channel=CppCon)
* [cppcon: Back to Basics Templates (part 2)](https://www.youtube.com/watch?v=0dtjDTEE0hQ&t=8s&ab_channel=CppCon)


## 2. Compile time programming
*Files*: [compile_time.cpp](./compile_time.cpp)

1. Explore compile time computations:
    1. `constexpr` `max` function
    2. Fibonacci numbers in compile time "the old way" using partial specialization of structures

2. Complete `TODO`s
    1. `TODO 1`: compute Fibonacci numbers using recursive function (`OPTIMIZED=false`, `PRECOMPUTED=false`)
    2. `TODO 2`: compute Fibonacci numbers using recursive function (`OPTIMIZED=true`, `PRECOMPUTED=false`)
    3. `TODO 3`: compute Fibonacci numbers the same way as in 2 but this time in `constexpr` function (`PRECOMPUTED=true`)

3. Compare compilation time and runtime of compile-time version and normal version using different values for `OPTIMIZED` and `PRECOMPUTED`
    * for `N=10`
    * for `N=100000`
    * for `N=1000000`

*Question:*
1. What limits did you hit?

*Hint*
* use Unix command `time` to measure the compilation time, runtime is measured inside C++ using high precision clock
```
labs-assignments/build$ time make labD_compile_time && ./labs/labD/labD_compile_time
```

*References:*
* [cppcon: Back to Basics const and constexpr](https://www.youtube.com/watch?v=tA6LbPyYdco&t=3114s&ab_channel=CppCon)

## 3. Type deduction

*Questions:*
1. What rvalues and lvalues are here?
``` c++
void foo(int && param) {
    param // lvalue or rvalue?
}

foo(10) // 10 is lvalue or rvalue?
```

1. How to get the type of variable?
    1. From IDE: Let your editor tell you (erroneous)
    2. Runtime: Use `std::typeid` (sometimes erroneous) or boost (external)
    3. Compile time: using *deliberate* compiler error m
        ```c++
        template<typename T>
        class TD;

        void foo()
        {
            TD<decltype(expr)> x;
            // Throws something like:
            // error: type ... has incomplete type and cannot be defined
        }
        ```

2. Try out `TD<T>` class template to find out type of some expression.

## 4. BONUS: Template meta-programming
*Files*: [type_programming.cpp](./type_programming.cpp)

1. Explore how `std::array` could be implemented on your own if you wanted to prevent usage of raw C pointers
