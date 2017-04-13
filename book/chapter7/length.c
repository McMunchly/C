/* determines the length of a message */
#include <stdio.h>

int main(void)
{
    int len = 0;
    
    printf("enter a message: ");
    
    while(getchar() != '\n')
        len++;
        
    printf("Your message was %d character(s) long\n", len);
    
    return 0;
}