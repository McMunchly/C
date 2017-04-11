/* beaufort scale */
#include <stdio.h>

int main(void)
{
    float speed;
    
    printf("Enter a wind speed (in knots): ");
    scanf("%f", &speed);
    
    if(speed < 1.0f)
        printf("Calm\n");
    else if(speed >= 1.0f && speed  < 4.0f)
        printf("Light air\n");
    else if(speed >= 4.0f && speed < 28.0f)
        printf("Breeze\n");
    else if(speed >= 28.0f && speed < 48.0f)
        printf("Gale\n");
    else if(speed >= 48.0f && speed < 64.0f)
        printf("Storm\n");
    else
        printf("Hurricane\n");

    return 0;
}