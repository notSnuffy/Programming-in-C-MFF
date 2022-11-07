#include <gtest/gtest.h>


TEST(TestSizeof, BaseTypes) {
    EXPECT_EQ(1, sizeof(bool));
    EXPECT_EQ(1, sizeof(char));
    EXPECT_EQ(4, sizeof(int));
    EXPECT_EQ(4, sizeof(int32_t));
    EXPECT_EQ(4, sizeof(long));
    EXPECT_EQ(8, sizeof(long long));
    EXPECT_EQ(8, sizeof(uint64_t));
    EXPECT_EQ(8, sizeof(std::size_t));
}

struct Foo {
    std::size_t x;
};

struct Bar {
    uint32_t a;
    bool b;
};

struct Baz {
    bool b;
    uint32_t a;
};

struct Com {
    uint32_t a[10];
};

struct __attribute__((__packed__))  FooBar {
    bool b;
    uint32_t a[10];
    char c;
};

TEST(TestSizeof, StructureTypes) {
    EXPECT_EQ(8, sizeof(Foo));
    EXPECT_EQ(8, sizeof(Bar));
    EXPECT_EQ(8, sizeof(Baz));
    EXPECT_EQ(40, sizeof(Com));
    EXPECT_EQ(42, sizeof(FooBar));
}
