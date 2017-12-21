/* Evaluate reverse polish notation for single-digit numbers*/

#include <stdbool.h>	/* C99 only */
#include <stdio.h>
#include "stackADT.h"

int main(void) {
	bool quit, stop = false;
	char ch;
	int i, op1, op2;
	
	Stack s;
		
	s = create();
		
	while(quit != true) {
		stop = false;
		printf("Enter an RPN expression: ");
		
		/* scan until the proper command is inputted */
		while(stop == false) {
			scanf(" %c", &ch);
			
			switch(ch) {
				case '0': case '1': case '2': case '3': case '4': case '5':
				case '6': case '7': case '8': case '9': case 10:
					push(s, ch - 48);
					break;
				case '+': case '-': case '*': case '/':
					op2 = pop(s);
					op1 = pop(s);
				
					if(ch == '+') {
						push(s, op1 + op2);
					} else if(ch == '-') {
						push(s, op1 - op2);
					} else if(ch == '*') {
						push(s, op1 * op2);
					} else {
						push(s, op1 / op2);
					}
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
		}
		
		printf("Value of expression: %d\n", pop(s));
		make_empty(s);
	}
	
	printf("\n");
		
	destroy(s);
	return 0;
}