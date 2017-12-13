/* guess whether 2 dice are low or high */

#include <stdio.h>	/* printf, scanf	*/
#include <stdlib.h> /* rand, srand 		*/
#include <time.h>	/* time 			*/

#define DIE 6
#define LOSE 10

int main(void) {
	
	int credits = 100, die1, die2, num, call, wager;
	char guess;
	
	srand(time(0));
	
	/* intro text and instructions */
	printf("\n----------Welcome to Low-High!!----------\n");
	printf("Two dice will be rolled, and a number will be given.\n");
	printf("Try to guess if the actual number is lower, higher, or correct.\n");
	printf("Enter 'q' to quit.\n");
	printf("-----\n\n");
	for(;;) {
		if(credits < 10) {
			printf("Out of credits. Game Over.\n");
			break;
		}
		
		die1 = (rand() % DIE) + 1;
		die2 = (rand() % DIE) + 1;
		num = die1 + die2;
		call = (rand() % (DIE * 2)) + 1;
		
		printf("The call is %d\n", call);
		
		printf("Credits: %d\n", credits);
		printf("Is the call low, high, or correct? (l/h/c): ");
		scanf(" %c", &guess);
		
		if(guess == 'q') {
			break;
		}
		
		if(guess != 'l' && guess != 'h' && guess != 'c') {
			printf("Invalid input. You lose.\n\n");
			credits -= LOSE;
		}
		
		printf("What is your wager?: ");
		scanf(" %d", &wager);

		while(wager < 1) {
			printf("Wager must be larger than 0\n");
			printf("What is your wager?: ");
			scanf(" %d", &wager);
		}
		
		if(wager > credits) {
			printf("All in!\n");
		}
		
		if((guess == 'l' && call < num) || (guess == 'h' && call > num)) {
			printf("\nCorrect!\n\n");
			credits += wager;
		} else if(guess == 'c' && call == num) {
			printf("\nCorrect! Match bonus!!!\n\n");
			credits += wager * 2;
		} else {
			printf("\nIncorrect. The number is %d\n\n", num);
			credits -= wager;
		}
	}
	
	printf("\n");
	return 0;
}