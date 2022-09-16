#ifndef _ARRAY_INITIALIZERS_C
#define _ARRAY_INITIALIZERS_C

#include <stdlib.h>
#include "array_initializers.h"

void initialize_array(int* arr, size_t len, int def) {
    for (size_t i = 0; i < len; i++) {
        arr[i] = def;
    }
}

#endif
