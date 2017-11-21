/* reverses a string with pointers */

#include <stdio.h>

#define MAX 100

int main(void)
{
	char ch, phrase[MAX], *index = phrase;
	
	printf("Enter a message: ");
	
	while((ch = getchar()) != '\n' && index < phrase + MAX) {
		
		*index = ch;
		index++;
	}
	
	/* pointer is one past the end of the array, so correct to last element */
	index--;
	
	printf("Reversal is: ");
	while(index >= phrase) {
		putchar(*index);
		index--;
	}

	putchar('\n');
	return 0;
}