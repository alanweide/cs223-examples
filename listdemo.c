#include <stdio.h>
#include "list.h"

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
        printLong(lst, "2");
    }
    printf("Done.\n");
    destroyList(lst);
}
