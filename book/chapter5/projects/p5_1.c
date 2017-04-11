/* prints out how many digits a number has */
#include <stdio.h>

int main(void)
{
    int number, digits;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    if(number >= 0 && number < 10)
        digits = 1;
    else if(number >= 10 && number < 100)
        digits = 2;
    else if(number >= 100 && number < 1000)
        digits = 3;
    else
        digits = 4;
        
    printf("The number %d has %d digits\n", number, digits);
    
    return 0;
}