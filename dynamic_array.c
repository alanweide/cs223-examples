#ifndef _DYNAMIC_ARRAY_C
#define _DYNAMIC_ARRAY_C

#include <stdlib.h>
// #include "dynamic_array.h"
#include "list.h"
#include "array_helpers.h"

#define HIGHLIGHTED "1;7"
#define FAINT "2"

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

size_t length(List arr) {
    return arr->curlen;
}

void append(List arr, int val) {
    if (arr->curlen >= arr->curmax) {
        arr->curmax *= 2;
        arr->a = realloc(arr->a, arr->curmax * sizeof(int));
    }
    arr->a[arr->curlen] = val;
    arr->curlen++;
}

int remove_last(List arr) {
    arr->curlen--;
    int last = arr->a[arr->curlen];
    if (arr->curlen < arr->curmax / 2) {
        arr->curmax /= 2;
        arr->a = realloc(arr->a, arr->curmax * sizeof(int));
    }
    return last;
}

void destroy_list(List arr) {
    free(arr->a);
    free(arr);
}

void printl(List arr) {
    // // Print the important part of the array
    // printf("\033[%sm", HIGHLIGHTED);
    // print_arr(arr->a, arr->curlen, HIGHLIGHTED);
    // printf("\033[0m")

    // // Print the entire allocated array
    // printf("\033[%sm", FAINT);
    // print_arr(arr->a, arr->curmax, FAINT);
    // printf("\033[0m")

    print_arr(arr->a, arr->curlen);
}

#endif