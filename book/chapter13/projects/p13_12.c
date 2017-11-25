/* reverse the words in a sentence with a string array */
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 30
#define WORD_LENGTH 20

int main(void)
{
	char sentence[MAX_LENGTH][WORD_LENGTH + 1];
	char ch = ' ', *p;
    int i, j;
    
    printf("Enter a sentence: ");

    for(i = 0; i < MAX_LENGTH; i++) {
        p = sentence[i];
        
        for(j = 0; j < WORD_LENGTH; j++) {
        	sentence[i][j] = getchar();
        	
        	if(sentence[i][j] == '.' || sentence[i][j] == '?' || sentence[i][j] == '!') {
        		ch = sentence[i][j];
        		break;
        	}
        	if(sentence[i][j] == ' ' || sentence[i][j] == '\n') {
        		break;
        	}
        }
        
        if(sentence[i][j] == '\n') {
			sentence[i][j] = '\0';
        	break;
        }
        
		sentence[i][j] = '\0';
        
    }

    printf("Reversal of sentence:");
    
    for(; i >= 0; i--) {
    	p = sentence[i];
        printf(" %s", p);
    }
    
    printf("%c\n", ch);
    
    return 0;
}