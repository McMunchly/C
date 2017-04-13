/* find average word length of a sentence */
#include <stdio.h>

int main(void)
{
    int words = 0, length = 0;
    float sum = 0, average;
    char c;
    
    printf("Enter a sentence: ");
    
    c = getchar();
    
    while(c != '\n')
    {
        if(c != ' ' && c != '\t')
        {
            if(length == 0)
            {
                words++;
            }
            length++;
        }
        
        else
        {
            sum += length;
            length = 0;
        }

        c = getchar();
    }
    sum += length;
    
    average = sum / words;
    printf("Average word length: %.1f\n", average);
    
    return 0;
}