#include <cassert>

#include <iostream>
#include <string>
#include <unordered_map>

struct S
{
    int i;
};

int main(void)
{
    {
        std::cout << "Task 1: create an unordered map with your custom key" << std::endl;
        std::unordered_map<S, std::string> smap{};
    }
    {
        std::cout << "Task 2: Insert elements into map using 3 different ways" << std::endl;
    }
    return 0;
}
