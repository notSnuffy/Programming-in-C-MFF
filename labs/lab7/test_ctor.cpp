#include <iostream>
#include <tuple>

#include <gtest/gtest.h>

#define DEBUG
//#define SOLUTION

struct CtorCounter {
    uint32_t empty{};
    uint32_t copy{};
    uint32_t move{};
    uint32_t copy_asgn{};
    uint32_t move_asgn{};
    uint32_t destructor{};

    auto get_tie() const {
        return std::tie(empty, copy, move, copy_asgn, move_asgn, destructor);
    }

    bool operator==(const CtorCounter & other) const {
        return get_tie() == other.get_tie();
    }
};

std::ostream & operator<<(std::ostream & os, const CtorCounter & counter) {
    #ifdef SOLUTION
        return os << "CtorCounter("
            << "empty:" << counter.empty
            << ", copy:" << counter.copy
            << ", move:" << counter.move
            << ", copy_asgn:" << counter.copy_asgn
            << ", move_asgn:" << counter.move_asgn
            << ", destructor:" << counter.destructor
            << ")";
    #else
        return os << "SOLUTION hidden";
    #endif
}

struct A {
    // Declare static member
    static CtorCounter counter;

    static void reset_counter() {
        counter = CtorCounter{};
    }

    int * x{};

    A() {
        ++counter.empty;
    }

    A(const A & other) {
        ++counter.copy;
    }

    A(A && other) {
        ++counter.move;
    }

    A & operator=(const A & other) {
        ++counter.copy_asgn;
        return *this;
    }

    A & operator=(A && other) {
        ++counter.move_asgn;
        return *this;
    }

    ~A() noexcept {
        ++counter.destructor;
    }
};

// Define static member in cpp file
CtorCounter A::counter;

// Test fixture that resets global environment before each test
struct TestCtorCount : ::testing::Test {
 protected:
    void SetUp() override {
        A::reset_counter();
    }
};

TEST_F(TestCtorCount, LocalCtor) {
    A x{};
    //std::cout << A::counter << std::endl;

    auto result = CtorCounter{.empty=1};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, CtorDtor) {
    {
        A x{};
    }
    auto result = CtorCounter{.empty=1, .destructor=1};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, Declare) {
    {
        A x;
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, BasicNewCtor) {
    {
        auto x = new A{};
        auto y = new A{};

        delete x;
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, ArrayCtor) {
    {
        A x[10];
        A * y = new A[10];
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, CopyCtor) {
    {
        A x{};
        A y{x};
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, CopyAsgn) {
    {
        A x{};
        A y = x;
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, CopyAsgn2) {
    {
        A x{};
        A y{};

        x = y;
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, Move) {
    {
        A x{};
        A y{std::move(x)};
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, MoveAsgn) {
    {
        A x{};
        A y{};
        x = std::move(y);
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, Asgn) {
    {
        A x;
        x = A{};
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

void bar(A a) {
    #ifdef DEBUG
        std::cout << "void bar(A)" << std::endl;
    #endif
}

TEST_F(TestCtorCount, Bar) {
    {
        A x{};
        bar(x);
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

void foo(A & a) {
    #ifdef DEBUG
        std::cout << "void foo(A &)" << std::endl;
    #endif
}

void foo(const A & a) {
    #ifdef DEBUG
        std::cout << "void foo(const A &)" << std::endl;
    #endif
}

void foo(A && a) {
    #ifdef DEBUG
        std::cout << "void foo(A &&)" << std::endl;
    #endif
}

TEST_F(TestCtorCount, Foo1) {
    {
        A x{};
        foo(x);
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, Foo2) {
    {
        A x{};
        foo(std::move(x));
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

A baz1() {
    A a{};
    return a;
}

TEST_F(TestCtorCount, Baz1) {
    baz1();

    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, RVO) {
    {
        A x = baz1();
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

A baz2() {
    A a{};
    return std::move(a);
}

TEST_F(TestCtorCount, Baz2) {
    {
        A x = baz2();
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

A * baz3() {
    A * a;
    return a;
}

A * baz4() {
    auto a = new A{};
    return a;
}

TEST_F(TestCtorCount, Baz34) {
    {
        auto x = baz3();
        x = baz4();
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

A & baz5() {
    auto a = new A{};
    return *a;
}

TEST_F(TestCtorCount, Baz5) {
    {
        auto x = baz4();
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, AddToVector1) {
    {
        std::vector<A> x{};
        x.push_back(A{});
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, AddToVector2) {
    {
        std::vector<A> x{};
        A y{};
        x.push_back(y);
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}

TEST_F(TestCtorCount, AddToVector3) {
    {
        std::vector<A> x{};
        A y{};
        x.push_back(std::move(y));
    }
    auto result = CtorCounter{};
    EXPECT_EQ(A::counter, result);
}


int destructor_counter = 0;

struct B {
    ~B() {
        ++destructor_counter;
    }
};

struct C : B {
    ~C() {
        ++destructor_counter;
    }
};

struct TestDestructorCounter : ::testing::Test {
 protected:
    void SetUp() override {
        destructor_counter = 0;
    }
};

TEST_F(TestDestructorCounter, DestructorCount1) {
    {
        C x;
    }
    EXPECT_EQ(destructor_counter, 0);
}

TEST_F(TestDestructorCounter, DestructorCount2) {
    {
        C * x = new C{};
        delete x;
    }
    EXPECT_EQ(destructor_counter, 0);
}

TEST_F(TestDestructorCounter, DestructorCount3) {
    {
        B * x = new C{};
        delete x;
    }
    EXPECT_EQ(destructor_counter, 0);
}
