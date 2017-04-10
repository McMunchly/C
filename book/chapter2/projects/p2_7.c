/* splits a dollar amount into highest bills */
#include <stdio.h>

int main(void)
{
    int dollars, twenties, tens, fives;
    
    printf("Enter a dollar amount: ");
    scanf("%d", &dollars);

    twenties = dollars / 20;
    dollars -= twenties * 20;
    tens = dollars / 10;
    dollars -= tens * 10;
    fives = dollars / 5;
    dollars -= fives * 5;
    
    printf("$20 dollar bills: %d\n", twenties);
    printf("$10 dollar bills: %d\n", tens);
    printf(" $5 dollar bills: %d\n", fives);
    printf(" $1 dollar bills: %d\n", dollars);
    return 0;
}