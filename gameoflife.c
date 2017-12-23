/* conway's game of life */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25

#define DEAD '.'
#define ALIVE 'X'
#define RANDOM 'r'

void fill_board(char board[], char type);
void print_board(char board[]);

int main(void) {
    char ch, board[SIZE * SIZE];
    int i, row, col, gen = 1, neighbors, neighbor_count[SIZE * SIZE];
    
    fill_board(board, DEAD);
    /* seed the random number generator */
    srand(time(0));
	/*
    board[10 + SIZE * 7] = ALIVE;
    board[11 + SIZE * 7] = ALIVE;
    board[12 + SIZE * 7] = ALIVE;
    board[13 + SIZE * 7] = ALIVE;
    board[14 + SIZE * 7] = ALIVE;
    board[15 + SIZE * 7] = ALIVE;
    board[16 + SIZE * 7] = ALIVE;
    board[17 + SIZE * 7] = ALIVE;
    board[18 + SIZE * 7] = ALIVE;
    board[19 + SIZE * 7] = ALIVE;
    */
    /*
    board[14 + SIZE * 14] = ALIVE;
    board[15 + SIZE * 14] = ALIVE;
    board[13 + SIZE * 15] = ALIVE;
    board[16 + SIZE * 15] = ALIVE;
    board[14 + SIZE * 16] = ALIVE;
    board[15 + SIZE * 16] = ALIVE;
    */
    
    board[10 + SIZE * 7] = ALIVE;
    board[11 + SIZE * 7] = ALIVE;
    board[9 + SIZE * 8] = ALIVE;
    board[10 + SIZE * 8] = ALIVE;
    board[10 + SIZE * 9] = ALIVE;
    
    /* main loop */
    for(;;) {
    	print_board(board);
    	printf("Generation %d\n", gen);
		printf("Enter command (h for help): ");
		scanf(" %c", &ch);
		
		/* parse commands */
		if(ch == 'h') {
			printf("COMMANDS\n"
					"n = proceed to next generation\n"
					"r = fill board randomly\n"
					"c = clear board\n"
					"x = make entire board alive\n"
					"f = input row and column to flip\n"
					"q = quit game\n");
			continue;
		} else if(ch == 'n') {
			gen++;
		} else if(ch == 'q') {
			break;
		} else if(ch == RANDOM) {
			fill_board(board, RANDOM);
			continue;
		} else if(ch == 'c') {
			fill_board(board, DEAD);
			continue;
		} else if(ch == 'x') {
			fill_board(board, ALIVE);
			continue;
		} else if(ch == 'f') {
			printf("Enter row and column to flip (r,c): ");
			scanf("%d,%d", &row, &col);
			if(board[SIZE * row + col] == DEAD) {
				board[SIZE * row + col] = ALIVE;
			} else {
				board[SIZE * row + col] = DEAD;
			}
			continue;
		} else {
			printf("invalid input\n");
			continue;
		}
		
		/* check all eight neighbors of each cell, and check edges */
		for(i = 0; i < SIZE * SIZE; i++) { 
            neighbors = 0;
            
 			/* top left neighbor */
 			if((i - SIZE - 1) >= 0 && (i - SIZE) % SIZE != 0) {
            	if(board[i - SIZE - 1] == ALIVE) {
                	neighbors++;
            	}
            }
            
            /* top neighbor */
            if((i - SIZE) >= 0) {
                if(board[i - SIZE] == ALIVE) {
                	neighbors++;
            	}
            }
            
            /* top right neighbor */
            if(((i - SIZE) + 1) > 0 && i % SIZE != SIZE - 1) {
            	if(board[(i - SIZE) + 1] == ALIVE) {
                	neighbors++;
            	}
            }
            
            /* left neighbor */
            if(i - 1 >= 0 && i % SIZE != 0) {
            	if(board[i - 1] == ALIVE) {
                	neighbors++;
            	}
            }
            
            /* right neighbor */
            if((i + 1) <= SIZE * SIZE && i % SIZE != 0) {
            	if(board[i + 1] == ALIVE) {
                	neighbors++;
            	}
            }
            
            /* bottom left neighbor */
            if(i + SIZE - 1 <= SIZE * SIZE && i % SIZE != 0) {
            	if(board[i + SIZE - 1] == ALIVE) {
                	neighbors++;
            	}
            }
            
            /* bottom neighbor */
            if(i + SIZE < SIZE * SIZE) {
                if(board[i + SIZE] == ALIVE) {
                	neighbors++;
            	}
            }
            
            /* bottom right neighbor */
            if(i + SIZE + 1 <= SIZE * SIZE && i % SIZE != SIZE - 1) {
            	if(board[i + SIZE + 1] == ALIVE) {
                	neighbors++;
            	}
            }
            
            neighbor_count[i] = neighbors;
        }
        
        /* set each cell according to the rules of Conway's game of life */
    	for(i = 0; i < SIZE * SIZE; i++) { 
            if(board[i] == ALIVE && neighbor_count[i] < 2) {
            	board[i] = DEAD;
            } else if(board[i] == ALIVE && neighbor_count[i] > 3) {
            	board[i] = DEAD;
            } else if(board[i] == DEAD && neighbor_count[i] == 3) {
            	board[i] = ALIVE;
            }
        }
    }
    
    return 0;
}

/* fills the board based on the given parameter */
void fill_board(char board[], char type) {
	int i;
	
    for(i = 0; i < SIZE * SIZE; i++) {
    	switch(type) {
			case DEAD:
				board[i] = DEAD;
				break;
			case ALIVE:
				board[i] = ALIVE;
				break;
			default:
				if(rand() % 2 == 0) {
        			board[i] = DEAD;
    			} else {
        			board[i] = ALIVE;
        		}
				break;
		}
    }
}

/* print the final result board */
void print_board(char board[]) {
	int i;
	printf("\n");

    for(i = 0; i < SIZE * SIZE; i++) { 
        if(i != 0 && i % SIZE == 0) {
            printf("\n");
        }
        printf("%c ", board[i]);
    }
        
    printf("\n");
}