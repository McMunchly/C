/* prints average test scores for students */
#include <stdio.h>

#define SIZE 5
int main(void)
{
    float row[SIZE][SIZE];
    int i = 0, j = 0;
    float sumrows[SIZE] = {0}, sumcolumns[SIZE] = {0};
    float averages[SIZE] = {0}, highest[SIZE], lowest[SIZE];
    while(i < SIZE)
    {
        printf("Enter student %d's grades: ", i + 1);
        
        while(j < SIZE)
        {
            scanf("%3f", &row[i][j]);
            j++;
        }
        
        j = 0;
        i++;
    }
    
    printf("\nStudent Averages: ");
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            sumrows[i] += row[i][j];
        }
        averages[i] = sumrows[i] / SIZE;
        
        printf("%.2f ", averages[i]); 
    }

    printf("\n");
    
    for(i = 0; i < SIZE; i++)
    {   
        highest[i] = row[0][i];
        lowest[i] = row[0][i];
        
        for(j = 0; j < SIZE; j++)
        {
            if(row[j][i] > highest[i])
                highest[i] = row[j][i];
            else if(row[j][i] < lowest[i])
                lowest[i] = row[j][i];
        }
        
        printf("\nQuiz %d - highest: %.2f lowest: %.2f", i + 1, highest[i], lowest[i]); 
    }
    printf("\n");
    
    return 0;
}