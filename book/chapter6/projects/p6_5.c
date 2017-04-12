/* reverse the digits of a number */
#include <stdio.h>

int main(void)
{
    int number, temp, newdigit = 0, newnum = 0, i = 0, j, ten = 1;
    
    printf("Enter a number: ");
    scanf("%d", &number);

    while(number > 0)
    {
        if(i != 0)
            ten *= 10;
            
        temp = number;
        
        /* figure out the power of ten of the digit */
        j = 1;
        while(temp > 10)
        {
            temp /= 10;
            j *= 10;
        }
        
        /* new digit is the last digit times the power of ten of the first */
        newnum += (number % 10) * j;

        number /= 10;
        i++;
    }
    printf("The digits reversed is: %d\n", newnum);
    
    return 0;
}