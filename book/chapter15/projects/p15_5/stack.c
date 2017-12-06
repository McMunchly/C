#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int top = 0;

bool underflow = false, overflow = false;

/* external variable */
extern int contents[STACK_SIZE];

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int i)
{
	if(is_full()) {
		printf("ERROR: stack overflow\n");
		exit(EXIT_FAILURE);
	} else {
		contents[top++] = i;
	}
}

int pop(void)
{
	if(is_empty()) {
		printf("ERROR: stack underflow\n");
		exit(EXIT_FAILURE);
	} else {
		return contents[--top];
	}
}

