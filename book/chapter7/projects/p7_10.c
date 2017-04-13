/* count the number of vowels in a sentence */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int count = 0;
    
    printf("Enter a sentence: ");
    
    ch = getchar();
    
    while(ch != '\n')
    {
        ch = toupper(ch);
        
        switch(ch)
        {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                count++;
                break;
            default:
                break;
        }
        ch = getchar();
    }
    
    printf("Your statement contains %d vowels.\n", count);
    
    return 0;
}