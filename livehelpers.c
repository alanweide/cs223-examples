#ifndef _LIVE_HELPERS_C
#define _LIVE_HELPERS_C

#include <stdio.h>

#define FMT_STRING "\t%6s = %zu: %d\n"
#define printvar(V, N) {printf(FMT_STRING, N, &V, V);}

int sumof(int a, int b) {
    printvar(a, "a");
    printvar(b, "b");
    return a + b;
}

int sumarr(int len, int arr[]) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        printvar(arr[i], "arr[i]");
        sum += arr[i];
    }
    return sum;
}

#endif