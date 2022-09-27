#include <stdio.h>
#include <stdlib.h>

// #include "dynamic_array.h"
#include "list.h"

int main(int argc, char** argv) {
    // size_t curlen = 0, curmax = 1;
    // int* arr = malloc(curmax * sizeof(int));
    List arr = create_list();
    int num = 0;
    while (fscanf(stdin, "%d", &num) > 0) {
        size_t list_len = length(arr);
        if (num > 0) {
            // Add a '1' to the (right) end of the array
            append(arr, list_len);
        } else if (num < 0 && list_len > 0) {
            // Remove the element at the (right) end of the array
            remove_last(arr);
        }
        printl(arr);
    }
    destroy_list(arr);
    printf("Done.\n");
}
