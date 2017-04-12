/* print all even squares */
#include <stdio.h>

int main(void)
{
    int n, i = 0;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    while(i * i <= n)
    {
        if((i * i) % 2 == 0 || i != 0)
            printf("%d\n", i * i);
        i++;
    }
    return 0;
}