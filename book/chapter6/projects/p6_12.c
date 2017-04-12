/* approximate value of e in a different way*/
#include <stdio.h>

int main(void)
{
    int i = 1, j, denom = 1;
    float frac, e = 1.0f;
    
    printf("Enter tiny decimal number to approximate e to: ");
    scanf("%f", &frac);
    
    while(1.0f / denom >= frac)
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
    
    printf("looped until term #%d\n", i);
    printf("e = %f\n", e);
    
    return 0;
}