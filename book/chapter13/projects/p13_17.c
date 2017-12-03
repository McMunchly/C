/* check if a string is a palindrome */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

int read_line(char str[], int n);
bool is_palindrome(const char *message);

int main(void)
{	
	char phrase[MAX + 1];
	
	printf("Enter a message: ");
	read_line(phrase, MAX + 1);
	
	if(is_palindrome(phrase)) {
		printf("Palindrome\n");
	} else {
		printf("Not a palindrome\n");
	}
	
	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while((ch = getchar()) != '\n' && i < n) {
		ch = tolower(ch);
		str[i++] = ch;
	}
		
	str[i] = '\0';
	
	return i;
}

bool is_palindrome(const char *message)
{
	bool palindrome = true;
	const char *p = message, *p2 = message;

	/* set second pointer to the null character */
	while(*p2 != '\0') {
		p2++;
	}
	
	/* move pointers towards the middle, comparing each element */
	for(p2--; p < p2; p2--, p++) {
		if(*p != *p2) {
			return false;
		}
	}
	
	return true;
}