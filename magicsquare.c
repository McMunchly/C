/* creates a magic square */
#include <stdio.h>

int main(void) {
    int size, i, j, row, col, oldrow, oldcol, sum = 0;
    
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &size);
    
    if(size % 2 == 0 || size > 99 || size < 1) {
        printf("Invalid number\n");
        return 0;
    }
    
    /* declare variable length array here - c99 only */
    int square[size][size];
    
    /* fill square with all 0's */
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            square[i][j] = 0;
        }
    }
    
    /* put 1 at the first row, middle column */
    row = 0;
    col = size / 2;
    square[0][size / 2] = 1;
    
    
    /* fill the magic square */
    for(i = 2; i <= size * size; i++) {
        /* store old coordinates in case an occupied space is found */
        oldrow = row;
        oldcol = col;
        
        /* move up a row and up a column - wrapping around the boundaries */
        row -= 1;
        col += 1;
        
        if(row < 0) {
            row = size - 1;
        }
            
        if(col == size) {
            col = 0;
        }
        
        /* if space is occupied, then go to old space up a row */
        if(square[row][col] != 0) {
            row = oldrow + 1;
            col = oldcol;
            
            if(row > size)
                row = 0;
        }
        
        square[row][col] = i;
    }
    
    /* print the square */
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            printf("%4d ", square[i][j]);
        }
            
        printf("\n");
    }

    printf("Row sums: ");
    
    /* find the sum of the first row - that's all rows and columns */
    for(i = 0; i < size; i++) {
        sum += square[0][i];    
    }
    
    printf("%-10d\nCol sums: %-10d", sum, sum);
    
    printf("\n");
    return 0;
}
