/* find the SCRABBLE score of a word */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int score = 0;
    char ch;
    
    printf("Enter a word: ");
    ch = getchar();
    
    while(ch != '\n')
    {
        ch = toupper(ch);
        
        switch(ch)
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
        
        ch = getchar();
    }
    
    printf("Scrabble value: %d\n", score);
    
    return 0;
}