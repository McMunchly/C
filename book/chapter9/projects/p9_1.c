/* sorts an array using a recursive selection sort */
#include <stdio.h>

#define N 10

void selection_sort(int a[], int limit);

int main(void)
{
    int a[N], i, highest;
    
    printf("Enter %d integers: ", N);
    
    for(i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    
    selection_sort(a, N);
    
    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    
    printf("\n");
    
    return 0;
}

void selection_sort(int a[], int limit)
{
    int i, largest = a[0], index = 0, temp;

    if(limit == 0)
        return;
        
    for(i = 0; i < limit; i++)
    {
        if(largest < a[i])
        {
            largest = a[i];
            index = i;
        }
    }
    
    temp = a[limit - 1];
    a[limit - 1] = largest;
    a[index] = temp;
    
    selection_sort(a, limit - 1);
}