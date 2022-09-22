#ifndef _LINKED_LIST_C
#define _LINKED_LIST_C

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct node {
    int payload;
    struct node* next;
} *Node;

struct impl_s {
    Node head;
    size_t curlen;
};

List createList() {
    List lst = malloc(sizeof(struct impl_s));
    lst->head = NULL;
    lst->curlen = 0;
    return lst;
}

size_t length(List lst) {
    size_t len = 0;
    Node head = lst->head;
    while (head != NULL) {
        head = head->next;
        len++;
    }
    return len;
}

void addToEnd(List lst, int val) {
    Node newHead = malloc(sizeof(struct node));
    newHead->payload = val;
    newHead->next = lst->head;
    lst->head = newHead;
}

int removeFromEnd(List lst) {
    Node oldHead = lst->head;
    lst->head = oldHead->next;
    int val = oldHead->payload;
    free(oldHead);
    return val;
}

void destoryNode(Node node) {
    if (node->next != NULL) {
        destoryNode(node->next);
    }
    free(node);
}

void destoryList(List lst) {
    destoryNode(lst->head);
    free(lst);
}

void printn(Node node) {
    if (node->next != NULL) {
        printn(node->next);
    }
    printf("%d ", node->payload);
}

void printl(List lst, char* colors) {
    printf("\033[%sm{ ", colors);
    if (lst->head != NULL) {
        printn(lst->head);
    }
    printf("}\033[0m");
}

void printLong(List lst, char* colors) {
    printl(lst, colors);
}
#endif
