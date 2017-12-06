/* Evaluate reverse polish notation for single-digit numbers*/

#include <stdbool.h>	/* C99 only */
#include <stdio.h>
#include <string.h>
#include "stack.h"

#define  MAX_LENGTH 80

/* external variable */
int contents[STACK_SIZE];

int read_line(char str[], int n);
int evaulate_RPN_expression(const char *expression);

int main(void)
{
	char phrase[MAX_LENGTH + 1];

	printf("Enter an RPN expression: ");
		
	/* store the expression as a string */
	read_line(phrase, MAX_LENGTH);
		printf("\n[%s]\n", phrase);
	printf("Value of expression: %d\n", evaulate_RPN_expression(phrase));
	make_empty();
	
	printf("\n");
	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while((ch = getchar()) != '\n' && i < n) {
		str[i++] = ch;
	}
		
	str[i] = '\0';
	
	return i;
}

int evaulate_RPN_expression(const char *expression)
{
	bool quit, stop = false, number = false;
	int i, op1, op2, num = 0;
	const char *ch = expression;
	
	/* scan until the proper command is inputted */
	while(stop == false) {
		switch(*ch) {
			case '0': case '1': case '2': case '3': case '4': case '5':
			case '6': case '7': case '8': case '9': case 10:
				/* check for numbers higher than one digit */
				if(number == false) {
					number = true;
					num = *ch - 48;
				} else {
					num *= 10;
					num += *ch - 48;
				}
				break;
			case '+': case '-': case '*': case '/':
				op2 = pop();
				op1 = pop();

				if(*ch == '+') {
					printf("%d + %d, %d\n", op1, op2, op1 + op2);
					push(op1 + op2);
				} else if(*ch == '-') {
					printf("%d - %d, %d\n", op1, op2, op1 - op2);
					push(op1 - op2);
				} else if(*ch == '*') {
					printf("%d * %d, %d\n", op1, op2, op1 * op2);
					push(op1 * op2);
				} else {
					printf("%d / %d, %d\n", op1, op2, op1 / op2);
					push(op1 / op2);
				}
				break;
			case 'q':
				return 0;
			case ' ':
				if(number) {
					number = false;
					push(num);
					num = 0;
				}
				break;
			case '=': case '\0':
				stop = true;
				break;
			default:
				printf("Invalid input: |%c|\n", *ch);
				return 0;
		}
			
		ch++;
	}
		
	return pop();
}