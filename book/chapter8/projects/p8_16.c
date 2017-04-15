/* checks if two words are anagrams */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int i, alpha[26] = {0};
    char ch;
    
    printf("Enter first word: ");
    
    ch = getchar();
    
    while(ch != '\n')
    {
        if(isalpha(ch))
        {
            ch = tolower(ch);
            alpha[ch - 'a'] += 1;
        }
        
        else
        {
            printf("you must only input alphabetical characters\n");
            return 0;
        }
        
        ch = getchar();
    }
    
    printf("Enter second word: ");
    
    ch = getchar();
    
    while(ch != '\n')
    {
        if(isalpha(ch))
        {
            ch = tolower(ch);
            alpha[ch - 'a'] -= 1;
        }
        
        else
        {
            printf("you must only input alphabetical characters\n");
            return 0;
        }
        
        ch = getchar();
    }
     
    printf("The words are");
    for(i = 0; i < 26; i++)
    {
        if(alpha[i] != 0)
        {
            printf(" not");
            break;
        }
    }
    
    printf(" anagrams\n");
    return 0;
}