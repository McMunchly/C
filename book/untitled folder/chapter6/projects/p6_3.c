/* reduce a fraction to lowerst terms */
#include <stdio.h>

int main(void)
{
    int num, denom, temp, n, m;
    
    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &denom);
    
    n = num;
    m = denom;
    
    while(n != 0)
    {   
        temp = m % n;
        m = n;
        n = temp;
    }
    
    printf("In lowest terms: %d/%d\n", num / m, denom / m);
    return 0;
}