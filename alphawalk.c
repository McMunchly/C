/* random walk across an array */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ALPHABET 25
#define SIZE 10
#define DIRECTIONS 4

int main(void)
{
    char alpha = 'A', board[SIZE * SIZE];
    int i, j, direction, current = 0;
    bool walk = false, choices[4] = {false};
    
    srand((unsigned) time(NULL));
       
    /* fill the board with '.' */ 
    for(i = 0; i < SIZE * SIZE; i++)
        board[i] = '.';
    
    board[current] = alpha;
    
    for(i = 0; i < ALPHABET; i++)
    {
        walk = false;
        direction = 0;
        
        for(j = 0; j < DIRECTIONS; j++)
            choices[j] = false;
        
        while(walk == false)
        {
            direction = rand() % DIRECTIONS;
            
            switch(direction)
            {
                case 0:
                    if(current - SIZE >= 0 && board[current - SIZE] == '.')
                    {
                        current -= SIZE;
                        board[current] = ++alpha;
                        walk = true;
                    }
                    else
                        choices[0] = true;

                    break;
                case 1:
                    if(current + 1 <= SIZE * SIZE && (current + 1) % 10 != 0 && board[current + 1] == '.')
                    {
                        current += 1;
                        board[current] = ++alpha;
                        walk = true;
                    }
                    else
                        choices[1] = true;

                    break;
                        
                case 2:
                    if(current + SIZE < SIZE * SIZE && board[current + SIZE] == '.')
                    {
                        current += SIZE;
                        board[current] = ++alpha;
                        walk = true;
                    }
                    else
                        choices[2] = true;

                    break;
                 case 3:
                    if(current - 1 <= SIZE * SIZE && current % 10 != 0 && board[current - 1] == '.')
                    {
                        current -= 1;
                        board[current] = ++alpha;
                        walk = true;
                    }
                    else
                        choices[3] = true;

                    break;
            }
                
            for(j = 0; j < DIRECTIONS; j++)
            {
                if(choices[j] == false)
                    break;
            }
            
            if(j == DIRECTIONS)
            {
                i = 50;
                break;
            }
        }
    }

    /* print the final result board */
    for(i = 0; i < SIZE * SIZE; i++)
    { 
        if(i != 0 && i % 10 == 0)
            printf("\n");
            
        printf("%c ", board[i]);

    }
    printf("\n");
    
    return 0;
}