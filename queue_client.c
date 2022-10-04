#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main(int argc, char** argv) {
    Queue q = create_queue();
    print_q(q);
    int num = 0;
    size_t i = 0;
    while (fscanf(stdin, "%d", &num) > 0) {
        if (num > 0) {
            // Add a number to the (right) end of the list
            enqueue(q, i);
        } else if (num < 0 && !is_empty_q(q)) {
            // Remove the element at the (right) end of the list
            dequeue(q);
        }
        print_q(q);
        i++;
    }
    destroy_queue(q);
    printf("Done.\n");
}
