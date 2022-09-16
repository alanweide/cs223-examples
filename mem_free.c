#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"

int main() {
    size_t curidx = 0, curmax = 1;
    int* arr = malloc(curmax * sizeof(int));

    // Repeadedly reads from input until it finds a non-integral sequence of characters or EOF, storing each value read in succesive elements of arr
    for (size_t i = 0; ; i++) {
        if (curidx == curmax) {
            malloc(4);
            printf("0x%zx -> %zu\n", arr, curmax);
            curmax += 1;
            arr = realloc(arr, curmax * sizeof(int));
        }
        arr[curidx] = i;
        curidx++;
    }
    printf("done.\n");
    print_arr(arr, 12);
}