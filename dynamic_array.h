#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H

typedef struct implementation* List;

List create_list();

void destroy_list(List lst);

size_t length(List lst);

void append(List arr, int val);

void remove_last(List arr);

void printl(List arr);

#endif
