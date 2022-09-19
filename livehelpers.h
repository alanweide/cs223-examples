#ifndef _LIVEHELPERS_H
#define _LIVEHELPERS_H

#include <stdio.h>

#define FMT_STRING "\t%6s = %zu: %d\n"
#define printvar(V, N) {printf(FMT_STRING, N, &V, V);}

int sumof(int a, int b);
int sumarr(int len, int arr[]);

#endif
