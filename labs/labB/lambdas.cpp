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

struct Searcher
{
    int item{};

    Searcher(int item) : item(item)
    {}

    bool operator()(int i) const
    {
        return i == item;
    }
};

struct Summer
{
    int sum{};

    void operator()(int i)
    {
        this->sum += i;
    }
};

int main(void)
{
    {
        std::cout << "Example 1: using functor instead of function" << std::endl;
        std::vector<int> v{9,8,1,2,8,7,9,4};

        Searcher searcher{2};
        auto it = std::find_if(v.cbegin(), v.cend(), searcher);
        if (it != v.cend()) {
            std::cout << "Found: " << searcher.item << " at index " << std::distance(v.cbegin(), it) << std::endl;
        } else {
            std::cout << "Not found: " << searcher.item << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::cout << "Example 2: using functor in different algorithm" << std::endl;
        std::vector<int> v{9,8,1,2,8,7,9,4};

        Summer summer{};
        Summer result = std::for_each(v.cbegin(), v.cend(), summer);
        std::cout << "Summer result: " << result.sum << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Task 1: rewrite examples 1 and 2 using lambdas" << std::endl;
        std::vector<int> v{9,8,1,2,8,7,9,4};
    }

    std::cout << std::endl;

    {
        constexpr int x = 5;
        std::cout << "Task 2: Find first element different from previous by at least " << x << std::endl;
        std::vector<int> v{9,8,1,2,8,7,9,4};
    }

    std::cout << std::endl;

    {
        constexpr int x = 100;
        std::cout << "Task 3: Increment numbers using following pattern: [v[i] + i*x | for v[i] in v]" << std::endl;
        std::vector<int> v{9,8,1,2,8,7,9,4};
    }

    std::cout << std::endl;

    {
        std::cout << "Task 4: Get difference of neighbor values in new container" << std::endl;
        std::vector<int> v{9,8,1,2,8,7,9,4};
        std::vector<int> result{};
    }

    return 0;
}
