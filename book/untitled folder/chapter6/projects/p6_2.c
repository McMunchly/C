/* find the greatest common denominator of two numbers */
#include <stdio.h>

int main(void)
{
    int n, m, temp, gcd;
    
    printf("Enter two integers: ");
    scanf("%d%d", &n, &m);
    
    while(n != 0)
    {   
        temp = m % n;
        m = n;
        n = temp;
    }
    
    printf("Greatest common divisor: %d\n", m);
    
    return 0;
}