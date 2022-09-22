#include <stdio.h>
#include <stdlib.h>

#include "array_initializers.h"

int main() {
    size_t x = 0;
    scanf("%zu", &x);
    if (x < 100) {
        int arr[x];
        initialize_array(arr, x, 0);
    }
    
    // Won't compile - why?
    // printf("%d\n", arr[0]);
}
