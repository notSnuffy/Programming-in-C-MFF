#include <iostream>
#include <memory>
#include <vector>

struct Base;
struct A;
struct B;

std::ostream & operator<<(std::ostream & os, const Base &);
std::ostream & operator<<(std::ostream & os, const A &);
std::ostream & operator<<(std::ostream & os, const B &);

struct Base
{
    virtual ~Base() = default;

    virtual std::unique_ptr<Base> clone() = 0;

    virtual void print()
    {
        std::cout << *this << std::endl;
    }
};

struct A : Base
{
    int i;

    A(int _i) {
        i = _i;
    }

    virtual std::unique_ptr<Base> clone() override {
        return std::make_unique<A>(i);
    }

    virtual void print() override {
        std::cout << *this << std::endl;
    }
};

struct B : Base
{
    std::string str;

    B(std::string _str) {
        str = _str;
    }

    virtual std::unique_ptr<Base> clone() override {
        return std::make_unique<B>(str);
    }

    virtual void print() override {
        std::cout << *this << std::endl;
    }
};


std::ostream & operator<<(std::ostream & os, const Base &)
{
    return os << "Base()";
}

std::ostream & operator<<(std::ostream & os, const A & a)
{
    return os << "A(" << a.i << ")";
}

std::ostream & operator<<(std::ostream & os, const B & b)
{
    return os << "B(" << b.str << ")";
}

//#define TASK_4
#ifdef TASK_4
struct C : Base
{
    std::vector<std::unique_ptr<Base>> container;

    virtual std::unique_ptr<Base> clone() override
    {
        // TODO
    }

    virtual void print() override
    {
        // TODO
    }
};

std::ostream & operator<<(std::ostream & os, const C &)
{
    // TODO
}
#endif
 

int main()
{
    // Task 1: Create a vector of pointers to Base and populate it with multiple As and Bs.

    std::vector<std::unique_ptr<Base>> vector;

    vector.push_back(std::make_unique<A>(1));
    vector.push_back(std::make_unique<B>("x2"));
    auto b = std::make_unique<B>("x2");
    auto copy_b =  b->clone();
    vector.push_back(std::move(copy_b));
    vector.push_back(std::make_unique<B>("x3"));
    vector.push_back(std::make_unique<B>("x4"));
    vector.push_back(std::make_unique<A>(5));
    vector.push_back(std::make_unique<A>(6));
    vector.push_back(std::make_unique<A>(7));

    for(auto && val : vector) {
        val->print();
    }



    // Task 2: Try to make a copy, what is the complain of the compiler.

    //auto vector2 = vector;

    // Task 3: Implement a clone operation on A and B and clone the vector.
    // What std algorithm could you use? (foreach + back_inserter).



    // Task 4: Uncomment Define of task 4 and create a clone operation for `struct C` a tree like structure.
    return 0;
}
