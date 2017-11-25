/* count the number of vowels in a sentence */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 80

int compute_vowel_count(const char *sentence);
int read_line(char str[], int n);

int main(void)
{
    int count = 0;
    char word[MAX_LENGTH + 1];
    
    printf("Enter a sentence: ");
    read_line(word, MAX_LENGTH);

    
    printf("Your statement contains %d vowels.\n", compute_vowel_count(word));
    
    return 0;
}

int compute_vowel_count(const char *sentence)
{
	int count = 0;
	
    while(*sentence != '\0') {
        switch(toupper(*sentence)) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                count++;
                break;
        }
        
		sentence++;
    }
    
    return count;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while((ch = getchar()) != '\n') {
		if(i < n) {
			str[i++] = ch;
		}
	}
		
	str[i] = '\0';
	
	return i;
}