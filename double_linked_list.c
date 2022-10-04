#ifndef _DOUBLE_LINKED_LIST_C
#define _DOUBLE_LINKED_LIST_C

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "stack.h"

typedef struct node {
    int payload;
    struct node* next;
    struct node* prev;
} *Node;

typedef struct implementation {
    // A pointer to the node that is the head of the list, or NULL if list is empty
    Node head;
    // A pointer to the node that is the tail of the list, or NULL if list is empty
    Node tail;
} dll_impl;

// Create a List
List create_list() {
    List lst = malloc(sizeof(dll_impl));
    lst->head = NULL;
    lst->tail = NULL;
    return lst;
}

Stack create_stack() {
    return (Stack)create_list();
}

// Returns true iff there are no elements in lst
bool is_empty(List lst) {
    return lst->head == NULL;
}

bool is_empty_s(Stack s) {
    return is_empty((List)s);
}

Node create_node(int val) {
    Node node = malloc(sizeof(struct node));
    node->payload = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Adds val to the (right) end of lst
void append(List lst, int val) {
    Node new_tail = create_node(val);
    Node old_tail = lst->tail;
    new_tail->prev = old_tail;
    if (is_empty(lst)) {
        lst->head = new_tail;
    } else {
        old_tail->next = new_tail;
    }
    lst->tail = new_tail;
}

void push(Stack s, int val) {
    append((List)s, val);
}

// Removes an element from the (right) end of lst and returns it
// Requires there is at least one element in the list
int remove_last(List lst) {
    Node old_tail = lst->tail;
    int val = old_tail->payload;
    lst->tail = old_tail->prev;
    if (lst->tail == NULL) {
        // lst had exactly one element in it; get rid of it
        lst->head = NULL;
    } else {
        lst->tail->next = NULL;
    }
    free(old_tail);
    return val;
}

int pop(Stack s) {
    return remove_last((List)s);
}

void destroy_node(Node node) {
    if (node->next != NULL) {
        destroy_node(node->next);
    }
    free(node);
}

// Frees the memory allocated by lst
void destroy_list(List lst) {
    if (!is_empty(lst)) {
        destroy_node(lst->head);
    }
    free(lst);
}

void destroy_stack(Stack s) {
    destroy_list((List)s);
}

// Prints the list
void printl(List lst) {
    Node node = lst->head;
    printf("%p->[ ", (void*)lst);
    while (node != NULL) {
        printf("%d ", node->payload);
        node = node->next;
    }
    printf("]\n");
}

void print_s(Stack s) {
    printl((List)s);
}

#endif
