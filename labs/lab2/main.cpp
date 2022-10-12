#include <iostream>
#include "sort.h"

void print(char **array, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    print(argv, argc);
    sort(argv + 1, argc - 1);
    print(argv + 1, argc - 1);
}
