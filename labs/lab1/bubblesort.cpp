#include <iostream>


void swap(char **a, char **b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void sort(char **array, int len) {
    for (int i = 0; i < len - 1; ++i){
        for (int j = 0; j < len - i - 1; ++j){
            if (*array[j] > *array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void print(char **array, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    ++argv;
    sort(argv, argc - 1);
    print(argv, argc - 1);
}
