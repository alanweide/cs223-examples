#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

// Type of a list that can be appended to and removed from and manage memory allocation automatically
typedef struct implementation *List;

// Create a List
List create_list();

// Returns the number of elements in lst
size_t length(List lst);

// Adds val to the (right) end of lst
void append(List lst, int val);

// Removes an element from the (right) end of lst and returns it
int remove_last(List lst);

// Frees the memory allocated by lst
void destroy_list(List lst);

// Prints the list
void printl(List lst);

#endif
