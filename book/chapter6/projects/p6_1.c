/* find the largest of a series of numbers */
#include <stdio.h>

int main(void)
{
    float number = 1.0f, entered;
    
    do
    {
        printf("Enter a number: ");
        scanf("%f", &entered);
        
        if(entered > number)
            number = entered;
    }
    while(entered > 0);
    
    printf("The largest number entered was %f\n", number);
    return 0;
}