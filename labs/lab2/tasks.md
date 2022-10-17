# Lab2 Tasks

## 1. Manual build
*Files:* [foo.cpp](./foo.cpp), [foo.h](./foo.h), [main.cpp](./main.cpp)

1. Run the preprocessor on the `foo.cpp` using `g++` option `-E`.

2. Compile to assembler (using option `-S`) and then paste it to the [Compiler Explorer](https://godbolt.org/).

3. Split `main.cpp` sort functionality into separate header `sort.h` and cpp file `sort.cpp`.

4. Compile object file (using `-c`) or compile the assembler directly.

5. Link those object files using `ld`. What is `_start`? Link instead with `g++ -v` and see how it calls the linker.

6. Check the type of each file using `file`, for ELF executables use `readelf -a`

*Questions:*
* How are header files processed?
* What is the difference between definition and declaration? Why do we need One Definition Rule?
* What are header guards?

*Resources:*
* `man file`
* `man g++`
* [Header/Include guards](https://en.wikipedia.org/wiki/Include_guard)
* [Compiler Explorer](https://godbolt.org/)
* [One definition rule](https://en.wikipedia.org/wiki/One_Definition_Rule)
* [C++ modules](https://en.cppreference.com/w/cpp/language/modules)
* `g++ -v`

## 2. Debugging info

1. Debug some binary from previous excercise with `gdb` using the notes from labs.

2. Add debug info try it again.

3. (Voluntary) Explore what different optimisation levels do to the code in [Compiler Explorer](https://godbolt.org/)

*Questions:*
* Does it make sense to compile with `-g` and `-O`?

## 3. Create static library

1. Compile `sort.cpp` from (1) into static library.
   Make a static library `libsort.a` out of it and move it to new directory `lib`.
   ```
   g++ -c sort.cpp -o libsort.o
   ar rvs libsort.a lisort.o
   ```
2. Link and run, explore with `g++ -v`
    ```
    g++ -c main.o
    g++ main.o -L./lib -lsort
    ```

3. Try move the header file to separate directory `inc` short for include, how to compile main? (explore option `-I`).

*Questions:*
* What is a static library?
* What do these options mean - `-L./lib -lsort`?
* What are the common standard library include directories?


## 4. Create dynamic library
1. Separate `print` functionality into print source and header file. Try to compile it using multiple object files linked together.

2. Make a dynamic/shared library `libprint.so` using options `-fPIC -shared -o libprint.so`. Explore it using `file`.

3. Compile main, pass in `libprint.so`. Try to run it why does it not work? Now set environment variable `LD_LIBRARY_PATH` and re-run. Explore it with `readelf -d <binary>` to view dynamic section.

4. Change and recompile the dynamic library only and re-run the program.

*Questions*
* What is -fPIC? (try search in the man page)
* Is StandardTemplateLibrary (std) library static or dynamic?


## Homework: MyC++ProjectTemplate (part 1)
Create your own C++ working environment familiarize yourselves with tools you want to be using, consider the following:
* compiler, setup generic tasks for debug and release (optimized) builds
* syntax highlighting, code navigation, auto completion or hints
* setup linter and stick to one style
* debugger

Play with the debugger and find a way how to:
* try setting (conditional) breakpoints
* evaluate expressions during run, create Watch
* explore call stack (stack trace) and jump between different stack frames
