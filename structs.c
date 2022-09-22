#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "dynamic_array.h"

#define HIGHLIGHTED "1;7"
#define FAINT "2"

int main(int argv, char** argc) {
    // size_t curlen = 0, curmax = 1;
    // int* arr = malloc(curmax * sizeof(int));
    List arr = create_list();
    int num = 0;
    while (fscanf(stdin, "%d", &num) > 0) {
        if (num > 0) {
            // Add a '1' to the (right) end of the array
            append(arr, 1);
        } else if (num < 0 && arr->curlen > 0) {
            // Remove the element at the (right) end of the array
            remove_last(arr);
        }

        // Print the important part of the array
        print_arr(arr->a, arr->curlen, HIGHLIGHTED);
        
        // Print the entire allocated array
        print_arr(arr->a, arr->curmax, FAINT);
    }
    printf("Done.\n");
}
