#include <array>
#include <iostream>

constexpr int max(int a, int b) 
{ 
    return (a > b) ? a : b;
} 

template<int N>
struct Fib
{
    static constexpr int value = Fib<N-1>::value + Fib<N-2>::value;
};

template<>
struct Fib<1>
{
    static constexpr int value = 1;
};

template<>
struct Fib<0>
{
    static constexpr int value = 0;
};

static constexpr bool OPTIMIZED = false;
static constexpr bool PRECOMPUTED = false;
static constexpr size_t N = 20;
constexpr std::array<size_t, N> precompute_fibonacci() {
    std::array<size_t, N> a{};
    // TODO 3: precompute fibonacci array the same way as in `compute_fibonacci`
    return a;
}
static constexpr auto precomputed_fibonacci = precompute_fibonacci();

std::array<size_t, N> compute_fibonacci() {
    std::array<size_t, N> a{};

    if constexpr (OPTIMIZED) {
        // TODO 2: compute fibonacci array using already precomputed values in `a`
    } else {
        // TODO 1: compute fibonacci array using non optimal recursive function
    }
    return a;
}

int main()
{
    {
        auto x = max(10000, 999999);
        std::cout << x << std::endl;
    }
    
    std::cout << std::endl;

    {
        std::cout << Fib<10>::value << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Computing: " << "Fibonacci(" << N << "), "
            << (OPTIMIZED ? "optimized" : "not-optimized") << ", "
            << (PRECOMPUTED ? "compile_time" : "runtime") << "... ";

        auto start = std::chrono::high_resolution_clock().now();
        size_t checksum = 0;

        if constexpr (PRECOMPUTED) {
            for (auto x : precomputed_fibonacci) {
                checksum += x;
            }
        } else {
            for (auto x : compute_fibonacci()) {
                checksum += x;
            }
        }
        auto end = std::chrono::high_resolution_clock().now();
        std::chrono::duration<double> diff = end - start;

        std::cout << "done" << std::endl
            << "Elapsed time (s): " << diff.count() << std::endl
            << "Checksum: " << checksum << std::endl;
    }
    return 0;
}
