/* check if a message is a palindrome */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

int main(void)
{
	bool palindrome = true;
	int i, j;
	char ch, phrase[MAX], *index = phrase, *start;
	
	printf("Enter a message: ");
	
	while(index < phrase + MAX) {
		ch = getchar();
		ch = tolower(ch);
		
		if(isalpha(ch)) {
			*index = ch;
			index++;
		}
		
		if(ch == '\n') {
			break;
		}
	}
	
	for(index--, start = phrase; index > phrase; index--, start++) {
		if(*index != *start) {
			palindrome = false;
			break;
		}
	}

	if(palindrome) {
		printf("Palindrome\n");
	} else {
		printf("Not a palindrome\n");
	}
	return 0;
}