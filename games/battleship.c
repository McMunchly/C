/* battle ship against the computer */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10

#define BLANK ','
#define HIT 'X'
#define MISS 'o'

void clear_board(char *board);
void print_board(char *board);

int main(void) {
	char ch, board[HEIGHT][WIDTH], *point = &board[0][0];
    int i, j, total, row, col, turns, ships, moves, states[HEIGHT][WIDTH] = {0};
    
    srand(time(0));
    
    /* intro text and instructions */
	printf("\n----------Welcome to Battleship!!----------\n");
	printf("There are ships hidden all over the board.\n");
	printf("Each turn input a row and column to attack.\n");
	printf("You win once all ships are destroyed!\n");
	printf("-----\n\n");
	
	printf("Enter difficulty (e,m,h): ");
	scanf(" %c", &ch);
	ch = tolower(ch);
	switch(ch) {
		case 'e':
			ships = 1;
			moves = 76;
			break;
		case 'h':
			ships = 3;
			moves = 26;
			break;
		default:
			ships = 2;
			moves = 51;
			break;
	}
	
	printf("%d ships and %d moves.\n", ships, moves - 1);
    clear_board(point);
    
    for(i = 0; i < ships; ) {
    	row = rand() % HEIGHT;
    	col = rand() % WIDTH;
    
    	if(col < HEIGHT - 2 && states[row][col] == 0 && states[row][col + 1] == 0 && states[row][col + 2] == 0) {
    		states[row][col] = 1;
    		states[row][col + 1] = 1;
    		states[row][col + 2] = 1;
    		/*board[row][col] = 's';
    		board[row][col + 1] = 's';
    		board[row][col + 2] = 's';
    		printf("%d %d\n", row, col);
    		printf("%d %d\n", row, col + 1);
    		printf("%d %d\n", row, col + 2); */
    		i++;
    	}
    }
  
   for(turns = 1, total = ships * 3; ;turns++) {
   		moves--;
   		
   		if(moves <= 0) {
   			printf("Out of moves. You lose.\n");
    		return 0;
   		}
   		
   		print_board(point);
   		printf("Moves remaining: %d\n", moves);
    	printf("Input row and column (negative number to quit): ");
    	scanf("%d %d", &row, &col);
    	
    	if(row < 0 || col < 0) {
    		printf("Goodbye\n");
    		return 0;
    	} else if(row >= HEIGHT || col >= WIDTH) {
    		printf("Too high. Invalid input\n");
    		continue;
    	}
    	
    	if(states[row][col] == 1) {
    		states[row][col] = 0;
    		board[row][col] = HIT;
    		printf("HIT!!!\n");
    		total--;
    		
    		/* check if the player has won yet */
    		if(total == 0) {
    			print_board(point);
    			printf("\nYou sunk all the battleships in %d turns!\n\n", turns);
    			break;
    		}
    	} else if((row > 0 && states[row - 1][col] == 1)
    			|| (row < HEIGHT && states[row + 1][col] == 1)
    			||	(col > 0 && states[row][col - 1] == 1)
    			||	(row < WIDTH && states[row][col + 1] == 1)) {
    		board[row][col] = MISS;
    		printf("NEAR HIT!\n");
    	} else {
    		board[row][col] = MISS;
    		printf("MISS.\n");
    	}  	
    } 

    return 0;
}

/* resets each cell of the board */
void clear_board(char *board) {
	char *p = board;
	int i, j;
	
    for(i = 0, j = 0; i < HEIGHT; i++) {
    	for(j = 0; j < WIDTH; j++, p++) {
    		*p = BLANK;
    	}
    }
}

/* print the final result board */
void print_board(char *board) {
	char *p = board;
	int i, j;
	printf("\n");

    for(i = 0, j = 0; i < HEIGHT; i++) {
    	for(j = 0; j < WIDTH; j++, p++) {
    		printf("%c ", *p);
    	}
    	printf("\n");
    }
}