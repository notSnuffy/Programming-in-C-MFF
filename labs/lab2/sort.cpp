#include "sort.h"

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

