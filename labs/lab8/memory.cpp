#include <memory>
#include <vector>
#include <iostream>

struct A {
    int x;
};

struct Common {
    int x;
};

struct B {
    std::shared_ptr<Common> x;
};

struct C {
    std::shared_ptr<Common> x;
};

void foo(std::unique_ptr<int> i) {
    std::cout << "void foo(std::unique_ptr<int> x)" << std::endl;
}

void foo(std::vector<std::unique_ptr<int>> & x) {
    std::cout << "void foo(std::vector<std::unique_ptr<int>> & x)" << std::endl;
}

int main() {
    {
        auto x = std::make_unique<A>();
        x->x = 10;
    }

    {
        auto x = std::make_shared<Common>();
        B b{x};
        C c{x};
    }

    // What does following code do?
    {
        std::vector<std::unique_ptr<int>> x;
        // Why does the first one compile but the second does not?
        x.emplace_back();
        // x.push_back();

        foo(x);

        foo(std::move(x.back()));
    }
}
