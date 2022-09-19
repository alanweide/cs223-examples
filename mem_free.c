#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"

int main() {
    size_t curidx = 0, curmax = 1;
    int* arr = malloc(curmax * sizeof(int));

    // Repeadedly reads from input until it finds a non-integral sequence of characters or EOF, storing each value read in succesive elements of arr
    for (size_t i = 0; ; i++) {
        if (curidx == curmax) {
            printf("0x%zx -> %zu\n", (size_t)arr, curmax);
            int oldmax = curmax;
            curmax += 1;
            int* newarr = malloc(curmax * sizeof(int));
            arr_copy(newarr, arr, oldmax);
            arr = newarr;
        }
        arr[curidx] = i;
        curidx++;
    }
    printf("done.\n");
    print_arr(arr, 12);
}
