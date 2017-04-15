/* shows repeated digits */

#include <stdio.h>
#include <stdbool.h>

#define LENGTH ((int) (sizeof(digit_seen) / sizeof(digit_seen[0])))

int main(void)
{
    bool digit_seen[10] = {false}, seen = false;
    int digit_repeat[10] = {0};
    int digit, i;
    long n;
    
    printf("Enter a number: ");
    scanf("%ld", &n);
    
    while(n > 0)
    {
        digit = n % 10;
            
        if(digit_seen[digit])
        {
            seen = true;
            digit_repeat[digit]++;
        }

        digit_seen[digit] = true;

        n /= 10;
    }
    
    if(seen)
    {
        printf("Repeated digit(s):");
        
        for(i = 0; i < LENGTH; i++)
        {
            if(digit_repeat[i] > 0)
                printf(" %d", i);
        }
        printf("\n");
    }
     
    else
        printf("No repeated digit\n");
        
    return 0;
}