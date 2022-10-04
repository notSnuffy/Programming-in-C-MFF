#include <iostream>

int EuclidianAlgorithm(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    int result = EuclidianAlgorithm(a, b);
    std::cout << result;
}
