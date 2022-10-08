#include <iostream>

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(char **array, int len) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < len; ++i) {
            if (*array[i - 1] > *array[i]) {
                swapped = true;
                swap(array[i - 1], array[i]);
            }
        }
    } while (swapped);
}

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
