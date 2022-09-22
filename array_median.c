#include <stdio.h>
#include <stdlib.h>

#include "array_initializers.h"
#include "array_helpers.h"

// Read in lines from input (each of which is a number) until a blank line or EOF is reached, and store those values in an array. Then prints the median of those numbers.
int main() {
    size_t size;

    // First line of input must be an unsigned integral value.
    if (fscanf(stdin, "%zu", &size) == 0) {
        fprintf(stderr, "No good: The first line is not an unsigned integral value\n");
        return 1;
    }

    int* arr = calloc(size, sizeof(int));
    size_t curidx = 0;

    // Repeadedly reads from input until it reads size integers, finds a non-integral sequence of characters, or finds EOF, storing each value read in succesive elements of arr
    while (curidx < size && fscanf(stdin, "%d", &arr[curidx++]) > 0);

    if (curidx != size) {
        fprintf(stderr, "No good: Input did not include the appropriate number of integer values\n");
        return 1;
    }

    int median = median_of_ints(arr, size);
    printf("median=%d\n", median);
    free(arr);
}
