/* turns a 24-hour time into 12-hour */
#include <stdio.h>

int main(void)
{
    int hour, minutes, pm = 0;
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minutes);
    
    if(hour == 24)
        hour = 0;
        
    if(hour > 12)
    {
        hour -= 12;
        pm = 1;
        }
        
    printf("Equivalent 12-hour time: %.2d:%.2d ", hour, minutes);
    
    if(pm == 1)
        printf("PM\n");
    else
        printf("AM\n");
        
    return 0;
}