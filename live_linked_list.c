#ifndef _LIVE_LIST_C
#define _LIVE_LIST_C

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node
{
    int payload;
    struct node* next;
};


struct implementation{
    struct node* head;
};

// Type of a list that can be appended to and removed from and manage memory allocation automatically
typedef struct implementation *List;

// Create a List
List create_list() {
    List lst = malloc(sizeof(struct implementation));
    lst->head = NULL;
    return lst;
}

// Returns true iff there are no elements in lst
bool is_empty(List lst) {
    return lst->head == NULL;
}

// Adds val to the (right) end of lst
void append(List lst, int val) {
    struct node* newHead = malloc(sizeof(struct node));
    newHead->payload = val;
    newHead->next = lst->head;
    lst->head = newHead;
}

// Removes an element from the (right) end of lst and returns it
// Assumes list is not empty
int remove_last(List lst) {
    struct node* oldHead = lst->head;
    int val = oldHead->payload;
    lst->head = lst->head->next;
    free(oldHead);
    return val;
}

// Assumes n is not null
void destroy_node(struct node* n) {
    if (n->next != NULL) {
        destroy_node(n->next);
    }
    free(n);
}


// Frees the memory allocated by lst
void destroy_list(List lst) {
    if (lst->head != NULL) {
        destroy_node(lst->head);
    }
    free(lst);
}

void printn(struct node* n) {
    if (n->next != NULL) {
        printn(n->next);
    }
    printf("%d ", n->payload);
}

// Prints the list
void printl(List lst) {
    printf("[ ");
    if (!is_empty(lst)) {
        printn(lst->head);
    }
    printf("]\n");
}

#endif
