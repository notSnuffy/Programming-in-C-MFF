# Lab 3 Tasks

## 1. Debugging info (lab2 rollover)

1. Debug some binary from previous excercise with `gdb` using the notes from labs.

2. Add debug info using `-g` and try it again.

*Questions:*
* Does it make sense to compile with debug info (`-g`) and optimization levels (`-O[123]`)?

## 2. Create dynamic library (lab2 rollover)
1. Separate `print` functionality into print source and header file. Try to compile it using multiple object files linked together.

2. Make a dynamic/shared library `libprint.so` using options `-fPIC -shared -o libprint.so`. Explore it using `file`.

3. Compile main, pass in `libprint.so`. Try to run it why does it not work? Now set environment variable `LD_LIBRARY_PATH` and re-run. Explore it with `readelf -d <binary>` to view dynamic section.

4. Change and recompile the dynamic library only and re-run the program.

*Questions:*
1. What is the difference between definition and declaration?
2. Why do we need One Definition Rule?
3. What are header guards?
4. What is -fPIC? (try search in the man page)
5. Is StandardTemplateLibrary (std) library static or dynamic?

## 3. C++ Build system - CMake

1. Clone [CMake GoogleTest Template project](https://gitlab.mff.cuni.cz/teaching/nprg041/drozdik/cmakegtesttemplate.git)

2. Build the cmake project manually or let your IDE build it (VSCode Cmake extension has some bug, please first do it manually)
    ```
    mkdir build
    cd build
    cmake ..
    make
    ```

> Notice no inherent dependency on any environment (Windows, Unix) that was one of the main goals of CMake, try to clone this project in IDE on different OS and it will, with a bit of luck, work.

## 4. Unit tests - Google test

*Files:* [testfoo.cpp](https://gitlab.mff.cuni.cz/teaching/nprg041/drozdik/cmakegtesttemplate/-/blob/master/test/testfoo.cpp)

1. Run tests on template project, either running binary directly or using `ctest` or using your IDE.

2. Take a look at [Simple Tests](https://google.github.io/googletest/primer.html#simple-tests) section  from the resources.

*Questions:*
* What are `TEST`, `ASSERT_` keywords?
* What is the difference between `ASSERT_` and `EXPECT_` macros?

*Resources:*
* [Google Test Primer](https://google.github.io/googletest/primer.html)

## 5. Linked lists

*Files:* [CMakeLists.txt](./CMakeLists.txt), [linked_list.h](./linked_list.h), [linked_list.cpp](./linked_list.cpp), [test_linked_list.cpp](./test_linked_list.cpp)

1. Header file creates some interface for the linked list. Test file already has some tests for few methods. Write implementation for that header file to make the tests pass.

2. Try out Test Driven Development (TDD) - first write new tests for `insert` and `erase` methods.

3. Now implement those methods so that your tests will pass.

## Homework: MyC++ProjectTemplate (part 2)
1. Convert your project template to CMake build system.

2. Add support for google test, or other test framework of your choosing.

3. (Bonus) Setup Gitlab Continuous Integration (CI) [.gitlab.yaml])https://gitlab.mff.cuni.cz/teaching/nprg041/drozdik/cmakegtesttemplate/-/blob/master/.gitlab-ci.yml)
