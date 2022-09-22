#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"

int main() {
    size_t curidx = 0, curmax = 1;
    int* arr = malloc(curmax * sizeof(int));

    // Stores consecutive integers in arr, reallocating arr as needed
    // int m = 1000000;
    // for (size_t i = 0; i < m; i++) {
    //     if (curidx == curmax) {
    //         printf("0x%zx -> %zu\n", (size_t)arr, curmax);
    //         int oldmax = curmax;
    //         curmax *= 2;
    //         arr = realloc(arr, curmax*sizeof(int));
    //     }
    //     arr[curidx] = i;
    //     curidx++;
    // }
    // for (size_t i = size - 1; i > 0; i--) {
    //     arr[i] = 0;
    //     if (i < curmax / 2) {
    //         // Shrink array
    //         curmax /= 2
    //         arr = realloc(arr, curmax);
    //     }
    // }
    int num = 0;
    while (fscanf(stdin, "%d", &num) > 0) {
        if (num >= 0) {
            // Add a '1' to the end of the array
            if (curidx > curmax) {
                curmax *= 2;
                arr = realloc(arr, curmax * sizeof(int));
            }
            arr[curidx] = 1;
            curidx ++;
        } else if (curidx > 0) {
            // Remove the last element of the array
            curidx--;
            if (curidx < curmax / 2) {
                curmax /= 2;
                arr = realloc(arr, curmax * sizeof(int));
            }
        }
        print_arr(arr, curidx, "");
    }
    printf("done.\n");
}
