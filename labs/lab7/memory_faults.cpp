#include <iostream>
#include <cassert>

int * foo() {
    int x = 666;
    return &x;
}

int main() {
    #if 1
        std::cout << "// Use after free" << std::endl;
        int * a = new int{42};
        std::cout << *a << std::endl;
        delete a;
        std::cout << *a << std::endl;
    #endif

    #if 1
        std:: cout << "// Out of bounds access" << std::endl;
        int * b = new int[10];
        std::cout << b[10] << std::endl;
        delete[] b;
    #endif

    #if 1
        std::cout << "// Memory leak" << std::endl;
        int * c = new int{};
    #endif

    #if 1
        std::cout << "// Doube free" << std::endl;
        int * d = new int{};
        delete d;
        delete d;
    #endif

    #if 1
        std::cout << "// Corrupting stack" << std::endl;
        auto e = foo();
        std::cout << *e << std::endl;
        *e = 42;
        std::cout << *e << std::endl;
    #endif
}
