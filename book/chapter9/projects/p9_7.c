/* find the power of a number with recursion */
#include <stdio.h>

int Power(int number, int exponent);

int main(void)
{
    int num, exp;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the exponent: ");
    scanf("%d", &exp);
    
    printf("%d ^ %d: %d\n", num, exp, Power(num, exp));
    
    return 0;
}

int Power(int number, int exponent)
{
    if(exponent == 0)
        return 1;

    number *= Power(number, exponent - 1);
    
    return number;
}