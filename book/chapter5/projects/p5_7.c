/* find largest of and smallest of four integers with four if statements */
#include <stdio.h>

int main(void)
{
    int num1, num2, num3, num4, largest, smallest;
    int largest2, smallest2;
    
    printf("Enter four integers: ");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
    
    if(num1 < num2)
    {
        largest = num2;
        smallest = num1;
    }
    else
    {
        largest = num1;
        smallest = num2;
    }
    if(num3 < num4)
    {
        largest2 = num4;
        smallest2 = num3;
    }
    else
    {
        largest2 = num3;
        smallest2 = num4;
    }
    
    if(largest < largest2)
        largest = largest2;
    if(smallest > smallest2)
        smallest = smallest2;
    
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);
    
    return 0;
}