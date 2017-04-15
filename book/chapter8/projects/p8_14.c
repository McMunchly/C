/* reverse the words in a sentence */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c, ch[99] = {' '};
    int i = 0, j;
    
    printf("Enter a sentence: ");
    
    c = getchar();

    while(c != '\n')
    {
        if(c == '.' || c == '\?')
            break;
        
        ch[i] = c;
        i++;
        c = getchar();
    }
    
    ch[i] = c;
    
    printf("Reversal of sentence:");
    
    for(i = 99 - 1; i >= 0; i--)
    {
        if(ch[i] == ' '|| i == 0)
        {
            if(i == 0)
                putchar(' ');

            for(j = i; ; j++)
            {
                ch[j] = tolower(ch[j]);
                
                if(j != i && (ch[j] == ' ' || ch[j] == '\n' || ch[j] == c))
                    break;
                    
                putchar(ch[j]);
            }
        }
    }
    
    printf("%c\n", c);
    
    return 0;
}