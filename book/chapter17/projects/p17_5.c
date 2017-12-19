/* sorts a series of words entered by the user */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20 /* max length of words */
#define MAX_WORDS 5 /* max number of words */

int read_line(char str[], int n);
int compare(const void *s1, const void *s2);

int main(void) {
	char *words[MAX_WORDS];
	char word[WORD_LEN + 1];
	
	int i, j, num_words = 0;
	
	for(i = 0; i < MAX_WORDS; i++) {
		
		printf("Enter word: ");
		read_line(word, WORD_LEN);
		
		if(word[0] == '\0') {
			break;
		}
		
		words[i] = malloc(2 + strlen(word) + 1);
		
		if(words[i] == NULL) {
			printf("-- No space left for words--\n");
			break;
		}
		
		strcat(words[i], word);
		
		num_words++;
	}
	
	qsort(words, num_words, sizeof(char *), compare);
		
	printf("\nIn sorted order: ");
	
	for(i = 0; i < num_words; i++) {
		printf("%s ", words[i]);
	}
	
	printf("\n");
	return 0;
}

int read_line(char str[], int n) {
	int ch, i = 0;
	
	while((ch = getchar()) != '\n') {
		if(i < n) {
			str[i++] = ch;
		}
	}
		
	str[i] = '\0';
	
	return i;
}

/* this function compares two strings for qsort function */
int compare(const void *s1, const void *s2) {
    const char **e1 = (const char **)s1;
    const char **e2 = (const char **)s2;
    
    return strcmp(*e1, *e2);
}