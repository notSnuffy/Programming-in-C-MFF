#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>

template <typename ForwardIt>
void print(ForwardIt begin, ForwardIt end)
{
    if (begin == end)
    {
        std::cout << "empty" << std::endl;
        return;
    }
    auto it = begin;
    for (; it + 1 < end; ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << *it << std::endl;
}

template <class Container>
void print(Container c)
{
    print(std::cbegin(c), std::cend(c));
}

int main(void)
{
    {
        std::cout << "Task 1: Find min/max of a vector" << std::endl;
        std::vector<int> v{9, 8, 1, 2, 8, 7, 9, 4};
        std::vector<int>::iterator min = std::min_element(v.begin(), v.end());
        if(min != v.end()) {
            std::cout << "Min element: " << *min << " at: " << std::distance(v.begin(), min) << std::endl;
        }
    }
    {
        std::cout << "Task 2: Find an element of a vector" << std::endl;
        std::vector<int> v{9, 8, 1, 2, 8, 7, 9, 4};
        auto result = std::find(v.begin(), v.end(), 8);
        (result != v.end()) ? (std::cout << "Vector contains element" << std::endl) : (std::cout << "Vector does not contain element" << std::endl);
    }
    {
        std::cout << "Task 3: Get a sum and product of a vector" << std::endl;
        std::vector<int> v{9, 8, 1, 2, 8, 7, 9, 4};
    }
    {
        std::cout << "Task 4: Get unique elements of a vector" << std::endl;
        std::vector<int> v{9, 8, 1, 2, 8, 7, 9, 4};
    }
    {
        std::cout << "Task 5: Set second half of a vector to `-1`" << std::endl;
        std::vector<int> v{9, 8, 1, 2, 8, 7, 9, 4};
    }
    return 0;
}
