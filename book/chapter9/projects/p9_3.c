/* random walk across an array with functions */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ALPHABET 25
#define SIZE 10
#define DIRECTIONS 4

void print_array(char walk[SIZE]);
void generate_random_walk(char walk[SIZE]);

int main(void)
{
    char board[SIZE * SIZE];
       
    generate_random_walk(board);
    print_array(board);
    
    return 0;
}
void generate_random_walk(char walk[SIZE])
{
    char alpha = 'A';
    int i, j, direction, coord = 0;
    bool go = false, choices[4] = {false};
    
    /* fill the board with '.' */ 
    for(i = 0; i < SIZE * SIZE; i++)
        walk[i] = '.';
    
    walk[coord] = alpha;
    
    srand((unsigned) time(NULL));
        
    for(i = 0; i < ALPHABET; i++)
    {
        go = false;
        
        for(j = 0; j < DIRECTIONS; j++)
            choices[j] = false;
        
        while(go == false)
        {
            direction = rand() % DIRECTIONS;
            
            switch(direction)
            {
                case 0:
                    if(coord - SIZE >= 0 && walk[coord - SIZE] == '.')
                    {
                        coord -= SIZE;
                        walk[coord] = ++alpha;
                        go = true;
                    }
                    else
                        choices[0] = true;

                    break;
                case 1:
                    if(coord + 1 <= SIZE * SIZE && (coord + 1) % 10 != 0 && walk[coord + 1] == '.')
                    {
                        coord += 1;
                        walk[coord] = ++alpha;
                        go = true;
                    }
                    else
                        choices[1] = true;

                    break;
                        
                case 2:
                    if(coord + SIZE < SIZE * SIZE && walk[coord + SIZE] == '.')
                    {
                        coord += SIZE;
                        walk[coord] = ++alpha;
                        go = true;
                    }
                    else
                        choices[2] = true;

                    break;
                 case 3:
                    if(coord - 1 <= SIZE * SIZE && coord % 10 != 0 && walk[coord - 1] == '.')
                    {
                        coord -= 1;
                        walk[coord] = ++alpha;
                        go = true;
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
}

void print_array(char walk[SIZE])
{
    int i;
    
    /* print the final board */
    for(i = 0; i < SIZE * SIZE; i++)
    { 
        if(i != 0 && i % 10 == 0)
            printf("\n");
            
        printf("%c ", walk[i]);

    }
    printf("\n");  
}