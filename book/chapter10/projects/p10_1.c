#include <stdbool.h>	/* C99 only */
#include <stdio.h>

#define STACK_SIZE 100

/* external variable */
char contents[STACK_SIZE];

int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);

int main(void)
{
	bool proper = true;
	char ch, left;
	
	printf("Enter parentheses and/or braces: ");
	
	while((ch = getchar()) != '\n') {
		if(ch == '{' || ch == '(' || ch == '[') {
			push(ch);
		} else if(ch == '}' || ch == ')' || ch == ']') {
			left = pop();
			if((left == '{' && ch == '}') || (left == '[' && ch == ']') || (left == '(' && ch == ')')) {
			} else {
				proper = false;
				break;
			}
		}
	}
	
	if(proper) {
		printf("Parentheses/braces are nested properly\n\n");
	} else {
		printf("Parentheses/braces are not nested properly\n\n");
	}
	return 0;
}

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

void push(char c)
{
	if(is_full()) {
		return;
	} else {
		contents[top++] = c;
	}
}

char pop(void)
{
	if(is_empty()) {
		return 0;
	} else {
		return contents[--top];
	}
}