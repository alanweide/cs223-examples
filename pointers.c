#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(sizeof(int)*4);
    arr[0] = 75;
    *(arr + 0) = 75;
    for (size_t i = 0; i < 4; i++) {
        arr[i] = i * 3;
    }
    printf("%d\n", arr);
    arr = malloc(sizeof(int)*8);
}