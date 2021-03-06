/* random walk across an array */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ALPHABET 25
#define SIZE 10
#define DIRECTIONS 4

int main(void) {
    char alpha = 'A', board[SIZE * SIZE];
    int i, j, direction, coord = 0;
    bool walk = false, choices[4] = {false};
    
    /* seed the random number generator */
    srand(time(0));
       
    /* fill the board with '.' */ 
    for(i = 0; i < SIZE * SIZE; i++)
        board[i] = '.';
    
    board[coord] = alpha;
    
    /* go until the alphabet is finished */
    for(i = 0; i < ALPHABET; i++) {
        walk = false;
        
        for(j = 0; j < DIRECTIONS; j++) {
            choices[j] = false;
        }
        
        while(walk == false) {
            direction = rand() % DIRECTIONS;
            
            switch(direction) {
                case 0:
                    if(coord - SIZE >= 0 && board[coord - SIZE] == '.') {
                        coord -= SIZE;
                        board[coord] = ++alpha;
                        walk = true;
                    } else {
                        choices[0] = true;
                    }

                    break;
                case 1:
                    if(coord + 1 <= SIZE * SIZE && (coord + 1) % SIZE != 0 && board[coord + 1] == '.') {
                        coord += 1;
                        board[coord] = ++alpha;
                        walk = true;
                    } else {
                        choices[1] = true;
                    }

                    break;
                        
                case 2:
                    if(coord + SIZE <= SIZE * SIZE && board[coord + SIZE] == '.') {
                        coord += SIZE;
                        board[coord] = ++alpha;
                        walk = true;
                    } else {
                        choices[2] = true;
                    }

                    break;
                 case 3:
                    if(coord - 1 >= 0 && coord % SIZE != 0 && board[coord - 1] == '.') {
                        coord -= 1;
                        board[coord] = ++alpha;
                        walk = true;
                    } else {
                        choices[3] = true;
					}

                    break;
            }
                
            for(j = 0; j < DIRECTIONS; j++) {
                if(choices[j] == false) {
                    break;
                }
            }
            
            if(j == DIRECTIONS) {
                i = 50;
                break;
            }
        }
    }

    /* print the final result board */
    for(i = 0; i < SIZE * SIZE; i++) { 
        if(i != 0 && i % 10 == 0) {
            printf("\n");
        }
            
        printf("%c ", board[i]);
    }
    
    printf("\n");
    return 0;
}
