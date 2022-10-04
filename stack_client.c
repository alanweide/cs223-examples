#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char** argv) {
    Stack s = create_stack();
    print_s(s);
    int num = 0;
    size_t i = 0;
    while (fscanf(stdin, "%d", &num) > 0) {
        if (num > 0) {
            // Add a number to the (right) end of the list
            push(s, i);
        } else if (num < 0 && !is_empty_s(s)) {
            // Remove the element at the (right) end of the list
            pop(s);
        }
        print_s(s);
        i++;
    }
    destroy_stack(s);
    printf("Done.\n");
}
