#include <stdio.h>
#include <stdlib.h>

#include "array_initializers.h"
#include "array_helpers.h"

// Read in lines from input (each of which is a number) until a blank line or EOF is reached, and store those values in an array.
int main() {
    size_t size;
    if (fscanf(stdin, "%zu", &size) == 0) {
        // The first line is not an unsigned integral value
        return 1;
    }

    int arr[size];
    size_t curidx = 0;

    // Repeadedly reads from input until it finds a non-integral sequence of characters or EOF, storing each value read in succesive elements of arr
    while (fscanf(stdin, "%d", &arr[curidx++]) > 0);

    if (curidx != size) {
        // The user did not input the appropriate number of integer values
        return 1;
    }

    int median = median_of_ints(arr, size);
    printf("median=%d\n", median);
}
