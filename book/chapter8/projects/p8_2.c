/* shows how many times each digit is repeated */

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
            
        digit_repeat[digit]++;

        n /= 10;
    }
    
    printf("Digit:\t\t0  1  2  3  4  5  6  7  8  9\n");
    printf("Occurences:\t");
    
    for(i = 0; i < LENGTH; i++)
    {
        printf("%-3d", digit_repeat[i]);
    }
    printf("\n");
        
    return 0;
}