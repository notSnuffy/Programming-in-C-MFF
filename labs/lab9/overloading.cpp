#include <sstream>
#include <string>
#include <iostream>

struct Coordinates {
    int x;
    int y;
};

Coordinates operator +(const Coordinates & a, const Coordinates & b) {
    return Coordinates{a.x + b.x, a.y + b.y};
}

std::ostream & operator<<(std::ostream & os, Coordinates c) {
    return os << '[' << c.x << ',' << c.y << ']';
}

int main() {
    Coordinates a{10, 5}; 
    Coordinates b{5, 7};
    Coordinates c = a + b;
    std::cout << c;
}

