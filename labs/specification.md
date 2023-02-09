# *Binary Search Trees*


> Fill in *emphasized text*, comments like these are supposed to guide you. Select best/all that apply, delete the rest.
> For submission send me the git commit hash of your project idea.

**Author:** *Holub Lukáš*

**Type:** *Library*

**Target Platform:** *Windows / Linux / Mac / embedded / ...*

**Perceived difficulty:** *5-7*

*Short description and motivation*
> 1-3 sentences about what you want to do and why
I have written library for shortest paths in C# so I thought I would try
to write a search tree library in C++ because the shortest paths library was
kind of fun to program

## User interface
*Programmers who need a search tree data structrute*

> Delete UI type that does not apply


### Library
> In markdown use three back quotes to create code block
```c++
class Search Tree
    function traverse;
    function insert;
    function delete;
    function find - maybe minimum, maximum, specific key;
```

> It would be nicer if you were to accomodate this within C++ algorithms infrastructure i.e. provide some interators that are appropriate for given type of binary tree.

> Something like simplified header file.

## Architecture

*templated class in header files for BST, AVL and probably red-black tree*

> If you go with red-black trees, that would be sufficient, otherwise doing BSt and AVL seems enough.

## Development & Testing
**Build system:** *CMake*

**Testing Framework:** *GoogleTest*

**Required libraries/frameworks:** *STD*

*Test if basic operations work correctly eventhough it is a bit difficult in graph-like data structures*
>Think about unit, functional, and performance tests.

> Unit tests are straight forward though you can never be sure of 100% correctness :-D. Do you want to try some performance tests as well and compare your implementation with some existing one?

## Acceptance criteria
> In software engineering it is common that your estimates are not met with reality. In order to reflect that decide how would you split your project into MVP and further enhancements/improvements. MVP should just meet the bar for final project submission. Extensions are additional features that you would like to add but don't consider them essential.

**Minimum Viable Product:*Basic operations for said trees*
> I'm not sure if this is enough, if you were to include some performance comparison test, that would be enough for "zapoctak".

**Extensions:*Maybe print function or some visualisation*
