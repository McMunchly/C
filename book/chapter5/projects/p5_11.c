/* print english word for a two-digit number */
#include <stdio.h>

int main(void)
{
    int number;
    
    printf("Enter a two-digit number: ");
    scanf("%d", &number);
    
    if(number < 10 || number > 99)
    {
        printf("invalid number\n");
        return 0;
    }
    
    printf("You entered the number ");
    
    switch(number / 10)
    {
        case 1:
            if(number % 10 == 0)
                printf("ten");
            else if(number % 10 == 1)
                printf("eleven");
            else if(number % 10 == 2)
                printf("twelve");
            else if(number % 10 == 3)
                printf("thirteen");
            else if(number % 10 == 4)
                printf("fourteen");
            else if(number % 10 == 5)
                printf("fifteen");
            else if(number % 10 == 6)
                printf("sixteen");
            else if(number % 10 == 7)
                printf("seventeen");
            else if(number % 10 == 8)
                printf("eighteen");
            else if(number % 10 == 9)
                printf("ninteen");
            
            number = 0;
            break;
        case 2:
            printf("twenty");
            break;
        case 3:
            printf("thirty");
            break;
        case 4:
            printf("forty");
            break;
        case 5:
            printf("fifty");
            break;
        case 6:
            printf("sixty");
            break;
        case 7:
            printf("seventy");
            break;
        case 8:
            printf("eighty");
            break;
        case 9:
            printf("ninety");
            break;
    }
    
    switch(number % 10)
    {
        case 0:
            printf(".\n");
            break;
        case 1:
            printf("-one.\n");
            break;
        case 2:
            printf("-two.\n");
            break;
        case 3:
            printf("-three.\n");
            break;
        case 4:
            printf("-four.\n");
            break;
        case 5:
            printf("-five.\n");
            break;
        case 6:
            printf("-six.\n");
            break;
        case 7:
            printf("-seven.\n");
            break;
        case 8:
            printf("-eight.\n");
            break;
        case 9:
            printf("-nine.\n");
            break;
        
    }
    
    return 0;
}