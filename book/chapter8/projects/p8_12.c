/* find the SCRABBLE score of a word with arrays */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int score = 0, values[7] = {1, 2, 3, 4, 5, 8, 10};
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
                score += values[0];
                break;
            case 'D': case 'G':
                score += values[1];
                break;
             case 'B': case 'C': case 'M': case 'P':
                score += values[2];
                break;
             case 'F': case 'H': case 'V': case 'W': case 'Y':
                score += values[3];
                break;
           case 'K': 
                score += values[4];
                break;
            case 'J': case 'X': 
                score += values[5];
                break;
            case 'Q': case 'Z':
                score += values[6];
                break;
        }
        
        ch = getchar();
    }
    
    printf("Scrabble value: %d\n", score);
    
    return 0;
}