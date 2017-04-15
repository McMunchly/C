/* translate a phrase into B1FF speak */
#include <stdio.h>
#include <ctype.h>

#define LENGTH ((int) (sizeof(c) / sizeof(c[0])))

int main(void)
{
    char c[99] = {' '}, ch;
    int i;
    
    printf("Enter message: ");
    
    ch = getchar();
    
    for(i = 0; ch != '\n'; i++)
    {
        c[i] = ch;
        ch = getchar();
    }
    
    printf("In B1FF-speak: ");
    
    for(int i = 0; i < LENGTH; i++)
    {
        c[i] = toupper(c[i]);
        
        switch(c[i])
        {
            case 'A':
                c[i] = '4';
                break;
            case 'B':
                c[i] = '8';
                break;
            case 'E':
                c[i] = '3';
                break;
            case 'I':
                c[i] = '1';
                break;
            case 'O':
                c[i] = '0';
                break;
            case 'S':
                c[i] = '5';
                break;
        }
        
        putchar(c[i]);
    }
    
    for(i = 0; i < 10; i++)
    {
        putchar('!');
    }

    printf("\n");
    
    return 0;
}