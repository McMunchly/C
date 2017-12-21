#ifndef QUEUE_H
#define QUEUE_H

typedef int Item;

typedef struct queue_type *Queue;

#include <stdbool.h>

Queue create(void);
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
void push(Queue q, Item i);
Item pop(Queue q);
Item get_first(Queue q);
Item get_last(Queue q);
#endif