#include <stdio.h>	/* printf, scanf 	*/
#include <stdlib.h>	/* rand, srand 		*/
#include <time.h>	/* time 			*/

#define COST 10
#define TWO 15
#define THREE 30

int RandomInt(int low, int high);

int main(void) {

	int a, b, c, credits = 100;
	char ch = 'a'; /* set this so the while loop will always be entered */
	
	/* seed the pseudo-random generator */
	srand(time(0));
		
 	while(ch != 'q') {
 		/* this won't be entered the first time because the user hasn't input yet */
		if(ch == 's') {
			if(credits >= 10) {
				credits -= 10;
				
				/* get the random slot results from 1-5 */
				a = RandomInt(1, 5);
				b = RandomInt(1, 5);
				c = RandomInt(1, 5);
			
				printf("\n%d	%d	%d\n", a, b, c);
				
				/* if the player has either 2 or three of a kind */
				if(a == b && b == c) {
					printf("Three of a kind! You win %d credits!\n", THREE);
					credits += THREE;
				} else if(a == b || b == c || a == c) {
					printf("Two of a kind! You win %d credits!\n", TWO);
					credits += TWO;
				} else {
					printf("No match. Try again.\n");
				}
			} else {
				printf("You don't have enough credits to continue. Game Over\n");
				return 0;
			}
		}
		
		/* prompt the user for a new action */
		printf("\nYour credits: %d\n", credits);
		printf("Press 's' to spin the slots (%d credits), press 'q' to quit: ", COST);
		scanf(" %c", &ch);
	}
    
	return 0;
}

/*
 * Gets a random int within the chosen range
 */
int RandomInt(int low, int high)
{
	int number = rand() % (high - low + 1) + low;
	return number;
}
