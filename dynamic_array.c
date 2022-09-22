#ifndef _DYNAMIC_ARRAY_C
#define _DYNAMIC_ARRAY_C

#include <stdlib.h>
#include "dynamic_array.h"

struct implementation  {
    size_t curlen;
    size_t curmax;
    int* a;
};

List create_list() {
    List lst = malloc(sizeof(struct implementation));
    lst->curlen = 0;
    lst->curmax = 1;
    lst->a = malloc(lst->curmax * sizeof(int));
    return lst;
}

void append(DynamicArray arr, int val) {
    if (arr->curlen >= arr->curmax) {
        arr->curmax *= 2;
        arr->a = realloc(arr->a, arr->curmax * sizeof(int));
    }
    arr->a[arr->curlen] = val;
    arr->curlen++;
}

void remove_last(DynamicArray arr) {
    arr->curlen--;
    if (arr->curlen < arr->curmax / 2) {
        arr->curmax /= 2;
        arr->a = realloc(arr->a, arr->curmax * sizeof(int));
    }
}

#endif