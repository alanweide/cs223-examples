#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

// A last-in, first-out sequence of ints
typedef struct implementation* Stack;

// Creates a new, empty Stack
Stack create_stack();

// Returns true iff there are no elements in s
bool is_empty_s(Stack s);

// Adds val to the top of s
void push(Stack s, int val);

// Removes and returnst the element at the top of the stack
int pop(Stack s);

// Frees all memory associated with s
void destroy_stack(Stack s);

// Prints the value of s to stdout
void print_s(Stack s);

#endif
