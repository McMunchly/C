/* reverse a 2 digit number */
#include <stdio.h>

int main(void)
{
    int number, digit1, digit2;
    
    printf("Enter a two-digit number: ");
    scanf("%2d", &number);
    
    digit1 = number % 10;
    digit3 = number / 10;
    
    printf("The reversal is: %1d%1d\n", digit1, digit2);
    
    return 0;
}