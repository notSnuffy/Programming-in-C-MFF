#include <cassert>

#include <iostream>
#include <string>
#include <unordered_map>

struct S
{
    int i;
};

struct SHash
{
    std::size_t operator()(S s) const {
        auto h = std::hash<int>{};
        return h(s.i); 
    }
};

struct SEquals
{
    std::size_t operator()(S s1, S s2) const {
        return s1.i == s2.i; 
    }
};

struct SAll
{
    std::size_t operator()(const S & s) const
    {
        std::cerr << "SAll::operator()(const S & s) const" << std::endl;
        return std::hash<int>()(s.i);
    }

    bool operator()(const S & s1, const S & s2) const
    {
        std::cerr << "SAll::operator()(const S & s1, const S & s2) const" << std::endl;
        return s1.i == s2.i;
    }
};

int main(void)
{
    {
        std::cout << "Task 1: create an unordered map with your custom key" << std::endl;
        std::unordered_map<S, std::string, SHash, SEquals> smap{};
        smap[S{1}] = "Hello";
    }
    {
        std::cout << "Task 2: Insert elements into map using 3 different ways" << std::endl;
        std::unordered_map<S, std::string, SHash, SEquals> smap{};
        smap[S{1}] = "Hello";
        smap.insert(std::pair(S{1}, "aa"));
        smap.emplace(S{1}, "aa");

    }
    return 0;
}
