/* evaluate a polynomial witha function*/
#include <stdio.h>

float polynomial(float x);

int main(void)
{
	float x;
	printf("Enter a value for x: ");
	scanf("%f", &x);

    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 =: ");
    printf("%f\n", polynomial(x));
    return 0;
}

float polynomial(float x)
{
    x = 3 * (x * x * x * x * x) + 2 * (x * x * x * x) - 5 * (x * x * x) - x * x + 7 * x - 6;   
    
    return x;
}