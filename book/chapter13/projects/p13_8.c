/* find the SCRABBLE score of a word */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 80

int compute_scrabble_value(const char *word);

int main(void)
{
    int score = 0;
    char word[MAX_LENGTH + 1];
    
    printf("Enter a word: ");
    scanf("%s", word);
    
    printf("Scrabble value: %d\n", compute_scrabble_value(word));
    
    return 0;
}

int compute_scrabble_value(const char *word)
{
	int score = 0;
	
    for(; *word != '\0'; word++) {
        switch(toupper(*word))
        {
            case 'A': case 'E': case 'I': case 'L': case 'N': case 'O':
            case 'R': case 'S': case 'T': case 'U':
                score += 1;
                break;
            case 'D': case 'G':
                score += 2;
                break;
             case 'B': case 'C': case 'M': case 'P':
                score += 3;
                break;
             case 'F': case 'H': case 'V': case 'W': case 'Y':
                score += 4;
                break;
           case 'K': 
                score += 5;
                break;
            case 'J': case 'X': 
                score += 8;
                break;
            case 'Q': case 'Z':
                score += 10;
                break;
        }
    }
    
    return score;
}