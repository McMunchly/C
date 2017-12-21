#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define SIZE 100

struct queue_type {
	Item data[SIZE];
	int top;
};

static void terminate(const char *message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void) {
	Queue q = malloc(sizeof(struct queue_type));
	
	if(q == NULL) {
		terminate("Error in create: stack could not be created.");
	}
	
	q->top = 0;
	return q;
}

void destroy(Queue q) {
	make_empty(q);
	free(q);
}

void make_empty(Queue q) {
	while(!is_empty(q)) {
		pop(q);
	}
}

bool is_empty(Queue q) {
	return q->top == 0;
}

bool is_full(Queue q) {
	return q->top == SIZE;
}

void push(Queue q, Item i) {
	
	if(is_full(q)) {
		terminate("Error in push: queue is full.");
	}
	
	q->data[q->top++] = i;
}

Item pop(Queue q) {
	int j;
	Item i;
	
	if(is_empty(q)) {
		terminate("Error in pop: queue is empty.");
	}

	i = q->data[0];

	for(j = 0; j < SIZE - 1; j++) {
		q->data[j] = q->data[j + 1];
	}
	
	q->top--;
	return i;
}

Item get_first(Queue q) {
	if(is_empty(q)) {
		terminate("Error in get_first: queue is empty.");
	}
	
	return q->data[0];
}
Item get_last(Queue q) {
	if(is_empty(q)) {
		terminate("Error in get_last: queue is empty.");
	}
	
	return q->data[q->top - 1];
}