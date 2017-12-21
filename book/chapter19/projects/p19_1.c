/* checks of braces and parantheses are nested properly with stacks */
#include <stdbool.h>	/* C99 only */
#include <stdio.h>
#include "stackADT.h"

int main(void) {
	Stack s;
	
	s = create();
	bool proper = true;
	char ch, left;
	
	printf("Enter parentheses and/or braces: ");
	
	while((ch = getchar()) != '\n') {
		if(ch == '{' || ch == '(' || ch == '[') {
			push(s, ch);
		} else if(ch == '}' || ch == ')' || ch == ']') {
			left = pop(s);
			
			if((left == '{' && ch == '}') || (left == '[' && ch == ']') || (left == '(' && ch == ')')) {
				continue;
			} else {
				proper = false;
				break;
			}
		}
	}
	
	if(proper && is_empty(s)) {
		printf("Parentheses/braces are nested properly\n\n");
	} else {
		printf("Parentheses/braces are not nested properly\n\n");
	}
	
	destroy(s);
	return 0;
}