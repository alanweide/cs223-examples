#include <stdio.h>
#include <stdlib.h>

#include "array_initializers.h"

int main() {
    size_t x = 0;
    scanf("%zu", &x);
    if (x < 100) {
        double arr[x];
        initialize_double_array(arr, x, 0);
    }
    
    // Won't compile - why?
    printf("%lf\n", arr[0]);
}
