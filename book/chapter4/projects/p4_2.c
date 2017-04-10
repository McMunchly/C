/* reverse a 3 digit number */
#include <stdio.h>

int main(void)
{
    int number, digit1, digit2, digit3;
    
    printf("Enter a three-digit number: ");
    scanf("%3d", &number);
    
    digit1 = number % 10;
    digit2 = (number % 100) / 10;
    digit3 = number / 100;
    
    printf("The reversal is: %1d%1d%1d\n", digit1, digit2, digit3);
    
    return 0;
}