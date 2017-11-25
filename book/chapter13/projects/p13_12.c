/* reverse the words in a sentence with a string array */
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 30
#define WORD_LENGTH 20

int main(void)
{
	char sentence[MAX_LENGTH][WORD_LENGTH + 1];
	char ch = ' ', *p, *p2;
    int i, j;
    
    printf("Enter a sentence: ");

    for(i = 0; i < MAX_LENGTH; i++) {
        p = p2 = sentence[i];
        
        /* check if the word is buffered by whitespace */
        *p2 = getchar();
        while(*p2 == ' ' || *p2 == '\t') {
        	p2++;
        	*p2 = getchar();
        }
        
        /* assign the first letter */
		*p = *p2;
		
		/* check for newline */
		if(*p == '\n') {
		    *p = '\0'; 
        	break;
        }
        
        p++;
        
        /* fill out the rest of the word */
        for(j = 0; j < WORD_LENGTH; j++, p++) {
			*p = getchar();
        	        	
        	/* record the ending punctuation */
        	if(*p == '.' || *p == '?' || *p == '!') {
        		ch = *p;
        		break;
        	}
        	
        	/* exit the word if a space or newline is found */
        	if(*p == ' ' || *p == '\n' || *p == '\t') {
        		break;
        	}
        }
        
        if(*p == '\n') {
			*p = '\0';
        	break;
        }
        
		*p = '\0';
    }

    printf("Reversal of sentence:");
    
    for(; i >= 0; i--) {
    	p = sentence[i];
    	if(*p != '\0') {
        	printf(" %s", p);
        }
    }
    
    printf("%c\n", ch);
    
    return 0;
}