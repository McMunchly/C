/* splits a dollar amount into highest bills */
#include <stdio.h>

void pay_amount(int dollars, int *twenty, int *ten, int *five, int *one);

int main(void)
{
    int dollars, twenties, tens, fives, ones;
    int *twenty = &twenties, *ten = &tens, *five = &fives, *one = &ones;
    
    do {
    	printf("Enter a dollar amount (enter 0 to quit): ");
    	scanf("%d", &dollars);
    	
    	pay_amount(dollars, twenty, ten, five, one);
    
		printf("$20 dollar bills: %d\n", twenties);
    	printf("$10 dollar bills: %d\n", tens);
	    printf(" $5 dollar bills: %d\n", fives);
    	printf(" $1 dollar bills: %d\n", ones);
    } while(dollars != 0);
    
    return 0;
}

void pay_amount(int dollars, int *twenty, int *ten, int *five, int *one)
{
	*twenty = dollars / 20;
    dollars -= *twenty * 20;
    *ten = dollars / 10;
    dollars -= *ten * 10;
    *five = dollars / 5;
    *one = dollars - *five * 5;
}