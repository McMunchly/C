/* Evaluate reverse polish notation for single-digit numbers*/

#include <stdbool.h>	/* C99 only */
#include <stdio.h>

#define STACK_SIZE 100

/* external variable */
int contents[STACK_SIZE];

bool overflow, underflow = false;

int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

int main(void)
{
	bool quit, stop = false;
	int i, op1, op2;
	char ch;
	
	while(quit != true) {
		stop = false;
		printf("Enter an RPN expression: ");
		while(stop == false) {
			scanf(" %c", &ch);
			
			switch(ch) {
				case '0': case '1': case '2': case '3': case '4': case '5':
				case '6': case '7': case '8': case '9': case 10:
					push(ch - 48);
					break;
				case '+':
					op2 = pop();
					op1 = pop();
				
					push(op1 + op2);
					break;
				case '-':
					op2 = pop();
					op1 = pop();
				
					push(op1 - op2);
					break;
				case '*':
					op2 = pop();
					op1 = pop();
				
					push(op1 * op2);
					break;
				case '/':
					op2 = pop();
					op1 = pop();
				
					push(op1 / op2);
					break;
				case 'q':
					return 0;
				case ' ':
					break;
				case '=':
					stop = true;
					break;
				default:
					printf("Invalid input: %c\n", ch);
					return 0;
			}
			
			if(overflow == true) {
				printf("Expression is too complex\n");
				return 0;
			} else if(underflow == true) {
				printf("Not enough operands in expression\n");
				return 0;
			}
		}
		
		printf("Value of expression: %d\n", pop());
		make_empty();
	}
	
	printf("\n");
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

void push(int i)
{
	if(is_full()) {
		overflow = true;
		return;
	} else {
		contents[top++] = i;
	}
}

int pop(void)
{
	if(is_empty()) {
		underflow = true;
		return 'x';
	} else {
		return contents[--top];
	}
}