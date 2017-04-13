/* convert 12-hour time into a 24-hour time */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, minutes, time;
    char ch;
    
    printf("Enter a 12-hour time: ");
    scanf("%d:%d ", &hour, &minutes);
    
    ch = getchar();
    ch = toupper(ch);

    
    if(hour == 12 && ch != 'P')
        hour = 0;
    
    if(hour != 12 && ch == 'P')
        hour += 12;
        
    printf("Equivalent 24-hour time: %.2d:%.2d\n", hour, minutes);  
    
    return 0;
}