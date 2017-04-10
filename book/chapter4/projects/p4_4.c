/* trnaslate an integer into octal */
#include <stdio.h>

int main(void)
{
    int number, digit1, digit2, digit3, digit4, digit5;
    
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &number);
    
    digit5 = number % 8;
    number /= 8;
    digit4 = number % 8;
    number /= 8;
    digit3 = number % 8;
    number /= 8;
    digit2 = number % 8;
    number /= 8;
    digit1 = number % 8;
    number /= 8;
    
    printf("In octal, your number is: %d%d%d%d%d\n", digit1, digit2, digit3, digit4, digit5);
    
    return 0;
}