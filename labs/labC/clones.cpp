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
    virtual std::unique_ptr<Base> clone() override;
};

struct B : Base
{
    virtual std::unique_ptr<Base> clone() override;
};


std::ostream & operator<<(std::ostream & os, const Base &)
{
    return os << "Base()";
}

std::ostream & operator<<(std::ostream & os, const A & a)
{
    return os << "A()";
}

std::ostream & operator<<(std::ostream & os, const B & b)
{
    return os << "B()";
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

    // Task 2: Try to make a copy, what is the complain of the compiler.

    // Task 3: Implement a clone operation on A and B and clone the vector.
    // What std algorithm could you use? (foreach + back_inserter).

    // Task 4: Uncomment Define of task 4 and create a clone operation for `struct C` a tree like structure.
    return 0;
}
