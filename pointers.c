#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t arrlen = 4;
    int *arr = malloc(sizeof(int)*arrlen);
    arr[0] = 75;
    for (size_t i = 0; i < arrlen; i++) {
        arr[i] = i * 3;
    }

    printf("%p\n", (void*)arr);

    // Make arr bigger
    arrlen *= 2;
    realloc(arr, sizeof(int)*arrlen);
    // int * old_value_of_arr = arr;
    // arr = malloc(sizeof(int)*arrlen);
    // memcpy(arr, old_value_of_arr, sizeof(int) * arrlen/2);
    // free(old_value_of_arr);

    printf("%p\n", (void*)arr);

    for (size_t i = 4; i < arrlen; i++) {
        arr[i] = i * 3;
    }


    // Print each element of arr
    printf("{ ");
    for (size_t i = 0; i < arrlen; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}