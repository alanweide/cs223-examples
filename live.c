#include <stdio.h>

#include "livehelpers.h"

int main() {
    printf("int x = 75;\n");
    fgetc(stdin);
    int x = 75;
    printvar(x, "x");

    printf("int arr[3];\n");
    fgetc(stdin);
    int arr[3];
    printf("\t%6s = %zu: %zu\n", "arr", &arr, arr);

    printf("int* arrp;\n");
    fgetc(stdin);
    int* arrp = malloc(sizeof(int));
    printvar(arrp, "arrp");

    printf("arr[0] = x;\n");
    fgetc(stdin);
    arr[0] = x;
    printvar(arr, "arr");
    printvar(arr[0], "arr[0]");

    printf("arr[1] = sumof(x, arr[0]);\n");
    fgetc(stdin);
    arr[1] = sumof(x, arr[0]);
    printvar(arr[1], "arr[1]");

    printf("arr[2] = sumarr(2, arr);\n");
    fgetc(stdin);
    arr[2] = sumarr(2, arr);
    printvar(arr[2], "arr[2]");

    printf("scanf(\"%%d\", x);\n");
    fgetc(stdin);
    scanf("%d", x);
    printvar(x, "x");

    printf("scanf(\"%%d\", &x);\n");
    fgetc(stdin);
    scanf("%d", &x);
    printvar(x, "x");

    printvar(arr[3], "arr[3]");
    printvar(arr+2, "arr+2");
    printf(FMT_STRING, "&x-1", &x - 1, *(&x - 1));
}
