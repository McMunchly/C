/* approximate value of e */
#include <stdio.h>

int main(void)
{
    int number, i = 1, j, denom;
    float e = 1.0f;
    
    printf("Enter interget to approximate e: ");
    scanf("%d", &number);
    
    while(i <= number)
    {
        j = 1;
        denom = 1;
        while(j <= i)
        {
            denom *= j;
            j++;
        }
        
        e += 1.0f/denom;
        i++;
    }
    
    printf("e = %f\n", e);
    
    return 0;
}