/* reformat a person's name using an array */
#include <stdio.h>

int main(void)
{
    char ch, first, last[20] = {' '};
    int i = 0;
    
    printf("Enter a first and last name: ");
    scanf(" ");
    
    first = getchar();
    
    ch = first;
    
    while(ch != ' ')
    {
        ch = getchar();
    }
    
    scanf(" ");
    
    ch = getchar();
    
    while(ch != '\n' && ch != ' ' && ch != '\t')
    {
        last[i] = ch;
        ch = getchar();
        i++;
    }
    
    printf("You entered the name: ");
    
    for(i = 0; i < 20; i++)
    {
        if(last[i] == ' ')
            break;
            
        putchar(last[i]);
    }
    
    printf(", %c.\n", first);
    
    return 0;
}