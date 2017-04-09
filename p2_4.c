/* add 5% tax to an amount */
#include <stdio.h>

int main(void)
{
	float amount;
	
	printf("Enter an amount: ");
	scanf("%f", &amount);
	
	printf("With tax added: $%.2f\n", amount + (amount * .05f));
    return 0;
}