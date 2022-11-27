#include "histogram.h"

#include <iostream>

int main() {
    Histogram h{std::cin};
    std::cout << h.char_count('c');
}