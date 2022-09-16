#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_helpers.h"
#include "array_initializers.h"

int main() {
    int *arr = malloc(sizeof(int)*4);
    initialize_array(arr, 4, 75);
    print_arr(arr, 4);

    arr = malloc(sizeof(int)*8);
    
    print_arr(arr, 8);
}