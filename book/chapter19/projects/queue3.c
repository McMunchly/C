#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
	Item data;
	struct node *next;
};

struct queue_type {
	struct node *top;
};

static void terminate(const char *message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void) {
	Queue q = malloc(sizeof(struct queue_type));
	
	if(q == NULL) {
		terminate("Error in create: queue could not be cretaed.");
	}
	q->top = NULL;
	
	return q;
}

void destroy(Queue q) {
	make_empty(q);
	//free(q);
}

void make_empty(Queue q) {
	while(!is_empty(q)) {
		pop(q);
	}
}

bool is_empty(Queue q) {
	return q->top == NULL;
}

bool is_full(Queue q) {
	return false;
}

void push(Queue q, Item i) {
	struct node *new_node = malloc(sizeof(struct node));
	
	if(new_node == NULL) {
		terminate("Error in push: queue is full.");
	}
	
	new_node->data = i;
	new_node->next = q->top;
	q->top = new_node;
}

Item pop(Queue q) {
	struct node *cur, *prev;
	Item i;
	
	if(is_empty(q)) {
		terminate("Error in pop: queue is empty.");
	}
	
	if(q->top->next == NULL) {
		i = q->top->data;
		free(q->top);
		q->top = NULL;
		return i;
	}
	
	for(cur = q->top, prev = NULL; cur->next != NULL; prev = cur, cur = cur->next) {
		;
	}
		
	i = cur->data;
	free(cur);
	prev->next = NULL;
	return i;
}

Item get_first(Queue q) {
	struct node *cur, *prev;
	
	if(is_empty(q)) {
		terminate("Error in get_first: queue is empty.");
	}
	
	for(cur = q->top, prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
		;
	}
	
	return prev->data;
}

Item get_last(Queue q) {
	if(is_empty(q)) {
		terminate("Error in get_last: queue is empty.");
	}
	
	return q->top->data;
}