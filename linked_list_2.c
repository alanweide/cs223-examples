#ifndef _LINKED_LIST_2_C
#define _LINKED_LIST_2_C

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct node {
    int payload;
    struct node* next;
} *Node;

struct implementation {
    Node head;
};

List create_list() {
    List lst = malloc(sizeof(struct implementation));
    lst->head = NULL;
    return lst;
}

bool is_empty(List lst) {
    return lst->head == NULL;
}

// Returns a pointer to the last node in the list
// Requires length(lst) > 0
Node last(List lst) {
    Node last = lst->head;
    while (last->next != NULL) {
        last = last->next;
    }
    return last;
}

void append(List lst, int val) {
    Node newTail = malloc(sizeof(struct node));
    newTail->payload = val;
    newTail->next = NULL;
    if (is_empty(lst)) {
        lst->head = newTail;
    } else {
        Node oldTail = last(lst);
        oldTail->next = newTail;
    }
}

// Returns a pointer to the second-to-last node in the list
// Requires length(lst) > 1
Node second_to_last(List lst) {
    Node last, prev;
    prev = lst->head;
    last = prev->next;
    while (last->next != NULL) {
        prev = last;
        last = prev->next;
    }
    return prev;
}

int remove_last(List lst) {
    Node oldTail;
    if (lst->head->next == NULL) {
        oldTail = lst->head;
        lst->head = NULL;
    } else {
        Node newTail = second_to_last(lst);
        oldTail = newTail->next;
        newTail->next = NULL;
    }
    int val = oldTail->payload;
    free(oldTail);
    return val;
}

void destroy_node(Node node) {
    if (node->next != NULL) {
        destroy_node(node->next);
    }
    free(node);
}

void destroy_list(List lst) {
    if (lst->head != NULL) {
        destroy_node(lst->head);
    }
    free(lst);
}

void printl(List lst) {
    printf("%p->[ ", (void*)lst);
    Node node = lst->head;
    while (node != NULL) {
        printf("%d ", node->payload);
        node = node->next;
    }
    printf("]\n");
}

#endif
