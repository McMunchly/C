/* enter a EAN code as a single number */
#include <stdio.h>

int main(void)
{
    int j1, j2, j3, j4, j5, j6, j7, j8, j9, j10, j11, j12,
        first_sum, second_sum, total;
        
    printf("Enter the first 2 digits of an EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5, &j6, &j7, &j8, &j9, &j10, &j11, &j12);
    
    first_sum = j2 + j4 + j6 + j8 + j10 + j12;
    second_sum = j1 + j3 + j5 + j7 + j9 + j11;
    total = (3 * first_sum) + second_sum;
    
    printf("Check digit: %d\n", 9 - ((total - 1) % 10));
    
    return 0;
}