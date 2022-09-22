#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

// Type of a list that can be appended to and removed from and manage memory allocation automatically
typedef struct impl_s *List;

// Create a List
List createList();

// Returns the number of elements in lst
size_t length(List lst);

// Adds val to the (right) end of lst
void addToEnd(List lst, int val);

// Removes an element from the (right) end of lst and returns it
int removeFromEnd(List lst);

// Frees the memory alllocated by lst
void destroyList(List lst);

// Prints the list with color options
void printl(List lst, char* colors);

// Prints the entire allocated list
void printLong(List lst, char* colors);

#endif
