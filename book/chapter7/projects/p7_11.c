/* reformat a person's name */
#include <stdio.h>

int main(void)
{
    char ch, first;
    
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
        putchar(ch);
        ch = getchar();
    }
    
    printf(", %c.\n", first);
    
    return 0;
}