#include "histogram.cpp"

#include <iostream>

int main() {
    Histogram h{std::cin};
    std::cout << h.char_count();
}