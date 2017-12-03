/* reverses a string with pointers */

#include <stdio.h>

#define MAX 100

int read_line(char str[], int n);
void reverse(char *message);

int main(void)
{
	char ch, phrase[MAX + 1];
	
	printf("Enter a message: ");
	
	read_line(phrase, MAX + 1);
	reverse(phrase);
	
	printf("Reversal is: %s\n", phrase);

	return 0;
}

void reverse(char *message)
{
	char ch, *p = message, *p2 = p;
	
	/* set second pointer to last element before the null character */
	while(*p2 != '\0') {
		p2++;
	}
	p2--;
	
	/* reverse first and last and move pointers inward until they meet */
	while(p < p2) {
		ch = *p;
		*p = *p2;
		*p2 = ch;
		
		p++, p2--;
	}
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