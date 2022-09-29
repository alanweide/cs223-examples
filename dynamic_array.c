#ifndef _DYNAMIC_ARRAY_C
#define _DYNAMIC_ARRAY_C

#include <stdlib.h>
#include "list.h"
#include "array_helpers.h"

#define RESIZE_RATIO 2

struct implementation  {
    size_t curlen;
    size_t capacity;
    int* a;
};

List create_list() {
    List lst = malloc(sizeof(struct implementation));
    lst->curlen = 0;
    lst->capacity = 1;
    lst->a = malloc(lst->capacity * sizeof(int));
    return lst;
}

bool is_empty(List arr) {
    return arr->curlen == 0;
}

void append(List arr, int val) {
    if (arr->curlen >= arr->capacity) {
        arr->capacity *= RESIZE_RATIO;
        arr->a = realloc(arr->a, arr->capacity * sizeof(int));
    }
    arr->a[arr->curlen] = val;
    arr->curlen++;
}

int remove_last(List arr) {
    arr->curlen--;
    int last = arr->a[arr->curlen];
    if (arr->curlen < arr->capacity / RESIZE_RATIO) {
        arr->capacity /= RESIZE_RATIO;
        arr->a = realloc(arr->a, arr->capacity * sizeof(int));
    }
    return last;
}

void destroy_list(List arr) {
    free(arr->a);
    free(arr);
}

void printl(List arr) {
    print_arr(arr->a, arr->curlen);
}

#endif