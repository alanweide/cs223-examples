#ifndef _LINKED_LIST_C
#define _LINKED_LIST_C

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "stack.h"

typedef struct node {
    int payload;
    struct node* next;
} *Node;

struct implementation {
    Node head;
    size_t curlen;
};

List create_list() {
    List lst = malloc(sizeof(struct implementation));
    lst->head = NULL;
    lst->curlen = 0;
    return lst;
}

Stack create_stack() {
    return (Stack)create_list();
}

bool is_empty(List lst) {
    return lst->head == NULL;
}

bool is_empty_s(Stack s) {
    return is_empty((List)s);
}

void append(List lst, int val) {
    Node newHead = malloc(sizeof(struct node));
    newHead->payload = val;
    newHead->next = lst->head;
    lst->head = newHead;
}

void push(Stack s, int val) {
    append((List)s, val);
}

int remove_last(List lst) {
    Node oldHead = lst->head;
    lst->head = oldHead->next;
    int val = oldHead->payload;
    free(oldHead);
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

void destroy_list(List lst) {
    if (lst->head != NULL) {
        destroy_node(lst->head);
    }
    free(lst);
}

void destroy_stack(Stack s) {
    destroy_list((List)s);
}

void printn(Node node) {
    if (node->next != NULL) {
        printn(node->next);
    }
    printf("%d ", node->payload);
}

void printl(List lst) {
    printf("%p->[ ", (void*)lst);
    if (lst->head != NULL) {
        printn(lst->head);
    }
    printf("]\n");
}

void print_s(Stack s) {
    printl((List)s);
}

#endif
