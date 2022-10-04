#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdbool.h>

// A first-in, first-out sequence of ints.
typedef struct implementation* Queue;

// Create a new, empty Queue
Queue create_queue();

// Returns true iff there are no elements in q
bool is_empty_q(Queue q);

// Addes val to q
void enqueue(Queue q, int val);

// Remove val from q
// Requires there is at least one element in q
int dequeue(Queue q);

// Frees all memory allocated for q
void destroy_queue(Queue q);

// Prints the value of q to stdout
void print_q(Queue q);

#endif
