/* prints row and colum sums of five rows of five integers */
#include <stdio.h>

#define SIZE 5
int main(void)
{
    int row[SIZE][SIZE];
    int i = 0, j = 0;
    int sumrows[SIZE] = {0}, sumcolumns[SIZE] = {0};
    
    while(i < SIZE)
    {
        printf("Enter row %d: ", i + 1);
        
        while(j < SIZE)
        {
            scanf("%d", &row[i][j]);
            j++;
        }
        
        j = 0;
        i++;
    }
    
    printf("Row totals: ");
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            sumrows[i] += row[i][j];
        }
        printf("%2d ", sumrows[i]); 
    }
    
    printf("\nColumn totals: ");
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            sumcolumns[i] += row[j][i];
        }
        printf("%2d ", sumcolumns[i]); 
    }
    printf("\n");
    
    return 0;
}