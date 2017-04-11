/* convert a numeric grade into a letter grade with a switch statement */
#include <stdio.h>

int main(void)
{
    int grade;
    
    printf("Enter numeric grade: ");
    scanf("%d", &grade);
    
    if(grade < 0 || grade > 100)
    {
        printf("invalid number\n");
        return 0;
    }
    
    grade = grade / 10;
    switch(grade)
    {
        case 10: case 9:
            printf("Letter grade: A\n");
            break;
        case 8:
            printf("Letter grade: B\n");
            break;
        case 7:
            printf("Letter grade: C\n");
            break;
        case 6:
            printf("Letter grade: D\n");
            break;
        default:
            printf("Letter grade: F\n");
            break;
    }

    return 0;
}