#ifndef _ARRAY_HELPERS_C
#define _ARRAY_HELPERS_C

#include <unistd.h>
#include <stdio.h>
#include "array_helpers.h"

int intcmp(const void *p, const void *q) {
    int a = *(int *)p, b = *(int *)q;
    if (a == b) {
        return 0;
    } else if (a < b) {
        return -1;
    } else {
        return 1;
    }
}

void sort_ints(int *nums, size_t len) {
    qsort(nums, len, sizeof(int), intcmp);
}

int median_of_ints(int* nums, size_t len) {
    sort_ints(nums, len);
    if (len % 2 == 0) {
        return (nums[len/2] + nums[len/2 - 1]) / 2;
    } else {
        return nums[len/2];
    }
}

void print_arr(int *arr, size_t len) {
    printf("0x%zx -> {", (size_t)arr);
    for (size_t i = 0; i < len; i++) {
        if (i > 0) {
            printf(",");
        }
        printf("%d", arr[i]);
    }
    printf("}\n");
}

int* array_with_default(int def, size_t len) {
    int* arr = malloc(len * sizeof(int));
    for (size_t i = 0; i < len; i++) {
        arr[i] = def;
    }
    return arr;
}

#endif
