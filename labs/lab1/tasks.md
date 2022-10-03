# Lab1 Tasks

## 1. Hello world - output and command-line arguments
*File: [hello.cpp](./hello.cpp)*

1. Write a program that prints `Hello world!`.

2. Say hello to an argument from command line.

3. Say hello to each arguments from command line separatelly.

*Resources*:
* [std::cout](https://en.cppreference.com/w/cpp/io/cout)
* [C main](https://en.cppreference.com/w/cpp/language/main_function)

## 2. Simple constructs
*File: [input.cpp](./input.cpp)*

1. Write euclidian algorithm (Greatest Common Divisor) of these two numbers (recursive or non-recursive).

*Resources*:
* [std::cin](https://en.cppreference.com/w/cpp/io/cin)
* [std::basic_istream](https://en.cppreference.com/w/cpp/io/basic_istream) - `.opertor>>`, `.fail`, `.good`, `.bad`

2. (voluntary) Try interactive debugging via debug console.
```
g++ -g input.cpp
gdb ./a.out
break <line after input is read>
run
<breakpoint hit>
print std::cin.fail()
```

> Alternatively use your IDE's debugger and add Watch on these functions.

## 3. Bubblesort
*File: [bubblesort.cpp](./bubblesort.cpp)*

1. Complete function `swap` that swaps values of two integers.

2. Sort cli arguments using `bubblesort` function, assume one character arguments.

*Resources*:
* [member access operators - `*a`, `&a`](https://en.cppreference.com/w/c/language/operator_member_access)
* `man ascii`
