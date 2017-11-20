/* reduce a fraction to lowest terms */
#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int num, denom;
    int *numer = &num, *denomer = &denom;
    
    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &denom);
    
    reduce(num, denom, numer, denomer);
    
    printf("In lowest terms: %d/%d\n", num, denom);
    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
	int temp, m, n;
	
	n = numerator;
    m = denominator;
    
	while(n != 0) {   
        temp = m % n;
        m = n;
        n = temp;
    }
    
    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;
}