/* reformat a telephone number */
#include <stdio.h>

int main(void)
{
    int area, middle, ending;
    
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &area, &middle, &ending);
    
    printf("You entered %d.%d.%d\n", area, middle, ending);
    
    return 0;
}