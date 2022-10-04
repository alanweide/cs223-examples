#ifndef _NAVIGABLE_LIST_H
#define _NAVIGABLE_LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
/* Type of a Navigable List.
A Navigable List is an ordered sequence of ints combined with a cursor. A use of a Navigable List may:
 - know whether there are any elements in the list
 - retrieve the position of the cursor, that is, the number of entries in the list that come before the cursor
 - move the cursor one position to the right ("advance" the cursor)
 - move the cursor one position to the left ("retreat" the cursor)
 - insert or remove an item at the position of the cursor (doing so will not change the cursor's position)
*/
typedef struct implementation {
    Stack front;
    Stack back;
} *Navigable_List;

// Create a List
Navigable_List create_navigable_list();

// Returns the current position of the cursor
int position(Navigable_List lst);

// Reports whether lst is empty
int is_empty_nl(Navigable_List lst);

// Advances the cursor one position to the right
void advance(Navigable_List lst) {
    int next = pop(lst->back);
    push(lst->front, next);
}

// Retreats the cursor one position
void retreat(Naviable_List lst) {
    int prev = pop(lst->front);
    push(lst->back, prev);
}

// Adds val to the lst at the current position
void insert(Navigable_List lst, int val) {
    push(lst->back, val);
}

// Removes an element from the lst at the current positioin and returns it
int remove(Navigable_List lst);

// Frees the memory allocated by lst
void destroy_list(Navigable_List lst);

// Prints the list
void print_nl(Navigable_List lst);

#endif
