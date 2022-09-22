#ifndef _RESIZING_LIST_C
#define _RESIZING_LIST_C

#include <stdlib.h>
#include "list.h"
#include "array_helpers.h"

#define INITIAL_CAP (1)
#define RESIZE_RATIO (2)

// Implementation struct for a List
struct impl_s {
    // Number of elements in this list
    size_t curlen;

    // Maximum number of elements this list can hold
    size_t curmax;

    // Pointer to array holding elements of this list
    int* a;
};

List createList() {
    List lst = malloc(sizeof(*lst));
    lst->curlen = 0;
    lst->curmax = INITIAL_CAP;
    lst->a = malloc(INITIAL_CAP * sizeof(int));
    return lst;
}

size_t length(List lst) {
    return lst->curlen;
}

void addToEnd(List lst, int val) {
    if (lst->curlen >= lst->curmax) {
        lst->curmax *= RESIZE_RATIO;
        lst->a = realloc(lst->a, lst->curmax * sizeof(int));
    }
    lst->a[lst->curlen] = 1;
    lst->curlen++;
}

int removeFromEnd(List lst) {
    lst->curlen--;
    int removed = lst->a[lst->curlen];
    if (lst->curlen < lst->curmax / RESIZE_RATIO) {
        lst->curmax /= RESIZE_RATIO;
        lst->a = realloc(lst->a, lst->curmax * sizeof(int));
    }
    return removed;
}

void destroyList(List lst) {
    free(lst->a);
    free(lst);
}

void printl(List lst, char* colors) {
    print_arr(lst->a, lst->curlen, colors);
}

void printLong(List lst, char* colors) {
    print_arr(lst->a, lst->curmax, colors);
}

#ifdef RES_MAIN
#include <stdio.h>
int main(int argv, char** argc) {
    List lst = createList();
    int num = 0;
    while (fscanf(stdin, "%d", &num) > 0) {
        if (num >= 0) {
            // Add a '1' to the end of the list
            addToEnd(lst, 1);
        } else if (length(lst) > 0) {
            // Remove the last element of the list
            removeFromEnd(lst);
        }

        // Print the important part of the list
        printl(lst, "1;7");

        // Print the entire allocated list
        print_arr(lst->a, lst->curmax, "2");
    }
    printf("Done.\n");
    destroyList(lst);
}
#endif

#endif
