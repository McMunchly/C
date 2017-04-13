/* prints a table of squares until user enters enter key */
#include <stdio.h>

int main(void)
{
    int i, n;
    char ch;
    
    printf("This program prints a table of squares.\n");
    printf("Print number of entries in table: ");
    scanf("%d", &n);
    
    /* take care of the initial newline left by scanf */
    ch = getchar();
    
    for(i = 1; i <= n ; i++)
    {
        printf("%10d%10d\n", i, i * i);
        
        if(i % 25 == 0)
        {
            printf("Press Enter to continue...");
            
            ch = getchar();
        }
    }
        
    return 0;
}