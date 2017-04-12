/* prints a formatted calendar */
#include <stdio.h>

int main(void)
{
    int days, week, i, count = 0;
    
    printf("Enter number of days in a month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &week);
    
    for(count = 1; count < week; count++)
    {
        printf("   ");
    }
    
    for(i = 1; i <= days; i++, count++)
    {       
        printf("%3d", i);
        
        if(count % 7 == 0)
            printf("\n");
    }
    
    printf("\n");
    return 0;
}