#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
Here is what the program will do:
1. Create a List and print it
2. Repeatedly read integers from input, each time:
    3. If the integer is positive, append that number to the right end of the List
    4. If the integer is negative and there are any items in the List, remove the rightmost item from the List
    5. Print the List
6. Free all of the memory that we used for the List
7. Print "Done."

What capabilities does our List need to have?
1. Create a list
2. Append something to the end
3. Remove something from the end
4. Print it
5. Destroy the list
6. Is the list empty?
*/
int main(int argc, char** argv) {
    List lst = create_list();
    printl(lst);
    int num = 0;
    size_t curlen = 0;
    while (fscanf(stdin, "%d", &num) > 0) {
        if (num > 0) {
            // Add a number to the (right) end of the list
            append(lst, curlen);
            curlen++;
        } else if (num < 0 && !is_empty(lst)) {
            // Remove the element at the (right) end of the list
            remove_last(lst);
            curlen--;
        }
        printl(lst);
    }
    destroy_list(lst);
    printf("Done.\n");
}
