/* find out which date comes earlier */
#include <stdio.h>

int main(void)
{
    int day1, month1, year1, day2, month2, year2;
    int earlier = 0;
    
    printf("Enter first date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &month1, &day1, &year1);
    
    printf("Enter second date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &month2, &day2, &year2);
    
    if(year1 < year2)
        earlier = 1;
    else if(year2 < year1)
        earlier = 2;
        
    if(earlier == 0)
    {
        if(month1 < month2)
            earlier = 1;
        else if(month2 < month1)
            earlier = 2;
    }  
    
    if(earlier == 0)
    {
        if(day1 < day2)
            earlier = 1;
        else if(day2 < day1)
            earlier = 2;
    }
    
    switch(earlier)
    {
        case 1:
            printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", month1, day1, year1, month2, day2, year2);
            break;
        case 2:
            printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", month2, day2, year2, month1, day1, year1);
            break;
        case 0:
            printf("The dates are the same\n");
    }
    
    return 0;
}