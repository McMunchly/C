/* checks numbers for repeated digits for multiple numbers */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool digit_seen[10] = {false};
    int digit;
    long n;
    
    printf("Enter a number (0 to terminate): ");
    scanf("%ld", &n);
    
    while(n > 0)
    {
    while(n > 0)
    {
        digit = n % 10;
        
        if(digit_seen[digit])
            break;
            
        digit_seen[digit] = true;
        n /= 10;
    }
        if(n > 0)
            printf("Repeated digit(s)\n");
        else
            printf("No repeated digits\n");
    
        printf("Enter a number (0 to terminate): ");
        scanf("%ld", &n);
    }
        
    return 0;
}