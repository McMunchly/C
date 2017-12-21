#include <stdio.h>
#include <stdlib.h>
#include "queue2.h"

struct queue_type {
	Item *data;
	int top;
	int size;
};

static void terminate(const char *message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(int size) {
	Queue q = malloc(sizeof(struct queue_type));
	
	if(q == NULL) {
		terminate("Error in create: queue could not be created.");
	}
	
	q->data = malloc(size * sizeof(Item));
	
	if(q->data == NULL) {
		free(q);
		terminate("Error in create: queue could not be created.");
	}
	
	q->top = 0;
	q->size = size;
	return q;
}

void destroy(Queue q) {
	free(q->data);
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
	return q->top == q->size;
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

	for(j = 0; j < q->size - 1; j++) {
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