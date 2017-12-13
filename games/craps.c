/* play craps 								*/

#include <stdio.h>		/* printf, scanf	*/
#include <stdbool.h>	/* bool				*/
#include <stdlib.h>		/* rand, srand		*/
#include <time.h>		/* time				*/

int roll_dice(void);
bool play_game(void);

int main(void) {
    char input;
    int wins = 0, losses = 0;
       
    srand(time(0));
        
	/* intro text and instructions */
	printf("\n----------Welcome to Craps!!----------\n");
	printf("Each game starts by rolling 2 dice.\n");
	printf("7 or 11 wins, 2, 3, and 12 lose\n");
	printf("Anything else is the point\n");
	printf("Roll until you roll the point (win!) or roll a 7 (lose).\n");
	printf("-----\n\n");
     
    for(;;) {
        if(play_game() == true) {
            wins++;
        } else {
            losses++;
        }
                   
        printf("\nPlay again? (y/n): ");
        input = getchar();
    
        if(input != 'y') {
            break;
        }
            
        scanf("%c", &input);
    }
    
    printf("\nWins: %d\tLosses: %d\n", wins, losses);
    
    return 0;
}

int roll_dice(void) {
	return ((rand() % 6) + 1) + ((rand() % 6) + 1);
}

bool play_game(void) {
    int point, result = roll_dice();
    
    printf("\nYou rolled: %d\n", result);
        
    /* first roll */
    switch(result) {
        case 7: case 11:
            printf("You win!\n");
            return true;
        case 2: case 3: case 12:
            printf("You lose!\n");
            return false;
        default:
            point = result;
            printf("Your point is %d\n", point);
            break;
    }
    
    /* roll until the players rolls a 7 or rolls the point */
    for(;;) {
        result = roll_dice();
        
        printf("You rolled: %d\n", result);
        
        if(result == point) {
            printf("You win!\n");
            return true;
        } else if(result == 7) {
            printf("You lose!\n");
            break;
        }
    }
    
    return false;
}
