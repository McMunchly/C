/* creates a magic square with functions */
#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void)
{
    int size;
    
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &size);
    
    if(size % 2 == 0 || size > 99 || size < 1)
    {
        printf("Invalid number\n");
        return 0;
    }
    
    /* declare variable length array here - c99 only */
    int square[size][size];
    
    create_magic_square(size, square);
    
    print_magic_square(size, square);
    
    printf("\n");
    return 0;
}

void create_magic_square(int n, int magic_square[n][n])
{
    int i, j, row, col, oldrow, oldcol;
    
    /* fill square with all 0's */
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            magic_square[i][j] = 0;
    }
    
    /* put 1 at the first row, middle column */
    row = 0;
    col = n / 2;
    magic_square[0][n / 2] = 1;
    
    
    /* fill the magic square */
    for(i = 2; i <= n * n; i++)
    {
        /* store old coordinates in case an occupied space is found */
        oldrow = row;
        oldcol = col;
        
        /* move up a row and up a column - wrapping around the boundaries */
        row -= 1;
        col += 1;
        
        if(row < 0)
            row = n - 1;
            
        if(col == n)
            col = 0;
        
        /* if space is occupied, then go to old space up a row */
        if(magic_square[row][col] != 0)
        {
            row = oldrow + 1;
            col = oldcol;
            
            if(row > n)
                row = 0;
        }
        
        magic_square[row][col] = i;
    }
}

void print_magic_square(int n, int magic_square[n][n])
{
    int i, j, sum = 0;
    
    /* print the square */
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%4d ", magic_square[i][j]);
            
        printf("\n");
    }
    

    printf("Row sums: ");
    
    /* find the sum of the first row - that's all rows and columns */
    for(i = 0; i < n; i++)
    {
        sum += magic_square[0][i];
            
    }
    
    printf("%-10d\nCol sums: %-10d", sum, sum);
}