/* play russian roulette until you die 	*/

#include <stdio.h>	/* printf, scanf	*/
#include <stdlib.h> /* rand, srand 		*/
#include <time.h>	/* time 			*/

int main(void) {
	
	int num, round = 1;
	char hand, ai_hand;
	
	srand(time(0));
		
	/* intro text and instructions		*/
	printf("---------Welcome to Russian Roulette----------\n");
	printf("Put in a bullet, spin the chamber, and fire.\n");
	printf("-----\n\n");
	for(;;) {
		printf("Bullet is chambered. Press 'f' to fire, 'q' to quit: ");
		scanf(" %c", &hand);
		
		if(hand == 'q') {
			break;
		}
		
		num = rand() % 6;
		
		if(num == 0) {
			printf("BOOM.\n\n");
			break;
		}
		
		else {
			printf("Click.\n");
			printf("You survived round %d.\n\n", round);
			round++;
		}
	}

	return 0;
}