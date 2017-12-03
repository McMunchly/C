/* checks if two words are anagrams */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 99

bool lowercase(char *word);
bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char ch, word1[MAX_LENGTH + 1] = {'\0'}, word2[MAX_LENGTH + 1] = {'\0'}, *p;
    
    printf("Enter first word: ");
    scanf("%s", word1);
    
    /* check that the word has no non-alpha characters, and lowercase string */
    if(lowercase(word1) == false) {
        return 0;
    }
    
    printf("Enter second word: ");
    scanf("%s", word2);
     
    /* check that the word has no non-alpha characters, and lowercase string */
    if(lowercase(word2) == false) {
        return 0;
    }
    
    printf("The words are");
    
    if(are_anagrams(word1, word2) == false) {
        printf(" not");
    }
    
    printf(" anagrams\n");
    return 0;
}

bool lowercase(char *word)
{	
    while(*word != '\0') {
        if(isalpha(*word)) {
        	*word = tolower(*word);
        } else {
        	printf("Only alphabetical characters are valid\n");
        	return false;
        }
        word++;
    }
    
    return true;
}

bool are_anagrams(const char *word1, const char *word2)
{
	int alpha[26] = {0}, *p;
	
	while(*word1 != '\0') {
		alpha[*word1 - 'a'] += 1;
        word1++;
    }
    
    while(*word2 != '\0') {
    	alpha[*word2 - 'a'] -= 1;
		word2++;
    }
    
	for(p = alpha; p < alpha + 26; p++) {
        if(*p != 0) {
            return false;
        }
    }
    
    return true;
}