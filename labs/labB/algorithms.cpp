#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>

template<typename ForwardIt>
void print(ForwardIt begin, ForwardIt end)
{
    if (begin == end) {
        std::cout << "empty" << std::endl;
        return;
    }
    auto it = begin;
    for ( ; it + 1 < end; ++it) {
        std::cout << *it << ", ";
    }
    std::cout << *it << std::endl;
}

template<class Container>
void print(Container c)
{
    print(std::cbegin(c), std::cend(c));
}

int main(void)
{
    {
        std::cout << "Task 1: Get a sum and product of a vector" << std::endl;
        std::vector<int> v{9,8,1,2,8,7,9,4};
        int sum = std::accumulate(v.begin(), v.end(), 0);
        std::cout << "Sum: " << sum << std::endl;
        int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
        std::cout << "Product: " << product << std::endl;
    }
    {
        std::cout << "Task 2: Get unique elements of a vector" << std::endl;
        std::vector<int> v{9,8,1,2,8,7,9,4};
        std::sort(v.begin(), v.end());
        auto last = std::unique(v.begin(), v.end());
        v.erase(last, v.end());
        print(v.begin(), v.end());
    }
    {
        std::cout << "Task 3: Set second half of a vector to `-1`" << std::endl;
        std::vector<int> v{9,8,1,2,8,7,9,4};

        std::fill(v.begin() + v.size() / 2, v.end(), -1);
        print(v.begin(), v.end());
    }
    return 0;
}
