#ifndef _LINKED_LIST_2_C
#define _LINKED_LIST_2_C

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "queue.h"

typedef struct node {
    int payload;
    struct node* next;
} *Node;

struct implementation {
    Node head;
    Node tail;
};

List create_list() {
    List lst = malloc(sizeof(struct implementation));
    lst->head = NULL;
    lst->tail = NULL;
    return lst;
}

Queue create_queue() {
    return (Queue)create_list();
}

bool is_empty(List lst) {
    return lst->head == NULL;
}

bool is_empty_q(Queue q) {
    return is_empty((List)q);
}

void append(List lst, int val) {
    Node newTail = malloc(sizeof(struct node));
    newTail->payload = val;
    newTail->next = NULL;
    if (is_empty(lst)) {
        lst->head = newTail;
    } else {
        lst->tail->next = newTail;
    }
    lst->tail = newTail;
}

void enqueue(Queue q, int val) {
    Node oldHead = q->head;
    Node newHead = malloc(sizeof(struct node));
    newHead->payload = val;
    newHead->next = oldHead;
    if (is_empty_q(q)) {
        q->tail = newHead;
    }
    q->head = newHead;
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
        lst->tail = newTail;
    }
    int val = oldTail->payload;
    free(oldTail);
    return val;
}

int dequeue(Queue q) {
    return remove_last((List)q);
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

void destroy_queue(Queue q) {
    destroy_list((List)q);
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

void print_q(Queue q) {
    printl((List)q);
}

#endif
