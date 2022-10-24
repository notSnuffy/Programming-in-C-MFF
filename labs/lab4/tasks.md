# Lab 4 Tasks

## 1. Linked lists (lab 4 rollover)

*Files:* continue in lab3 directory

1. What is wrong with the linked list interface?

2. Try out Test Driven Development (TDD) - first write new tests for `insert` and `erase` methods.

3. Now implement those methods so that your tests will pass.


## 2. How much memory do your types consume?

*Files:* [test_sizeof.cpp](./test_sizeof.cpp)

1. Fill in the expected size of the types, in the `EXPECT_EQ`.

2. Run the tests and verify


## 3. Decide whether lines with `// ?` contain an error?

``` c++
// Basic types
const int a;
const int a[3] = {1, 2, 3};

// Basic objects
struct Foo {
  int i;
  const int j; // ? - tricky one

  void bar();

  void baz() const; // object method `const` modifier
};

// Declaration and Initialization
Foo foo{};
const Foo const_foo{}; // without {} it does not work, why?

void foobaz(const Foo f) {
  f.bar(); // ?
  f.baz(); // ?
}

void foobar(Foo f) {
  f.baz(); // ?
  f.j = 5; // ?
}

void cref(const Foo & f);
void ref(Foo & f);

int task_constness() {
  const_foo.bar(); // ?
  const_foo.baz(); // ?
  const_foo.i = 1; // ?
  const_foo.j == 42; // ?

  foobar(foo); // ?
  foobar(const_foo); // ?

  foobaz(foo); // ?
  foobaz(const_foo); // ?

  ref(foo); // ?
  ref(const_foo); // ?

  cref(foo); // ?
  cref(const_foo); // ?
}


#include <iostream>
void Foo::bar() {
  std::cout << j; // ?
}

void Foo::baz() const { // notice the const at the end without it this is invalid!
  i = 5; // ?
}

// Pointers
int * p_int;
int *is_pointer_to_int, not_a_pointer_int;
int * is_pointer_to_int1, * is_pointer_to_int2;

int const * pointer_const_int; // east notation
const int * wpointer_const_int; // west notation

int * const const_pointer_to_int;
int const * const const_pointer_const_int; // east notation
const int * const wconst_pointer_const_int; // west notation

void pointer_test() {
    int i;
    int const ci; // east notation

    int * p1 = &ci; // ?
    int * const p2 = &ci; // ?
    int * const p3 = &i; // ?
    const int * p4 = &i; // ?
    int const * const p5 = &i; // ?
}
```

*References:*
* https://en.cppreference.com/w/cpp/language/cv

*Notes:*
* `const` is part of the type!
* That holds for methods as well!

## 5. Automatic type deduction

1. Figure out what is the type of these expressions.

2. Verify with intellisense.

``` c++
{
    int x = 0;
    auto a = x; // ?
    auto & ar = x; // ?
}
{
    const int x = 1;
    auto a = x; // ?
    auto & ar = x; // ?
    const auto & car = x; // ?
}
{
    int const * x = nullptr;
    auto a = x; // ?
    auto & ar = x; // ?
}
```

*References:*
* [C++ weekly episode on `auto`](https://www.youtube.com/watch?v=tn69TCMdYbQ&ab_channel=C%E1%90%A9%E1%90%A9WeeklyWithJasonTurner)
