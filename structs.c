#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
Here is what the program will do:
1. Create a List and print it
2. Repeatedly read integers from input, each time:
    3. If the number is positive, append [current length of the List] to the right end of the List
    4. If the number is negative and there are any numbers in the List, remove the rightmost number from the List
    5. Print the List
6. Free all of the memory that we used for the List
7. Print "Done."

What capabilities does our List need to have?
1. 
*/
int main(int argc, char** argv) {
    List lst = create_list();
    printl(lst);
    int num = 0;
    while (fscanf(stdin, "%d", &num) > 0) {
        size_t list_len = length(lst);
        if (num > 0) {
            // Add a number to the (right) end of the list
            append(lst, list_len);
        } else if (num < 0 && list_len > 0) {
            // Remove the element at the (right) end of the list
            remove_last(lst);
        }
        printl(lst);
    }
    destroy_list(lst);
    printf("Done.\n");
}
