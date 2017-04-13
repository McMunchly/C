/* compute the square root of a positive floating-point number */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double number, square, y = 1.0, average;
    
    printf("Enter a positive number: ");
    scanf("%lf", &number);
    
    square = number / y;
    average = (y + square) / 2.0;
    
    while(fabs(average - y) > .0000f * average)
    {
        y = average;
        square = number / y;
        average = (y + square) / 2.0;
        
        printf("%f  %f  %f\n", y, square, average);
    }
    
    printf("Square root: %f\n", average);
    return 0;
}