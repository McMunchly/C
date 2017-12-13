/* rock-papers-scissors game 			*/

#include <stdio.h>	/* printf, scanf	*/
#include <stdlib.h> /* rand, srand 		*/
#include <time.h>	/* time 			*/

int main(void) {
	
	struct record {
		int wins;
		int losses;
		int draws;
	} rec = {0, 0, 0};
	
	int num;
	char hand, ai_hand;
	
	srand(time(0));
		
	/* intro text and instructions */
	printf("---------Welcome to Rock-Papers-Sissors!!----------\n");
	printf("-----\n\n");
	for(;;) {
		printf("Choose your hand (r/p/s), enter q to quit: ");
		scanf(" %c", &hand);
		
		if(hand == 'q') {
			break;
		}
		
		if(hand != 'r' && hand != 'p' && hand != 's') {
			printf("Invalid input\n\n");
			continue;
		}
		
		num = rand() % 3;
		
		switch(num) {
			case 0:
				ai_hand = 'r';
				break;
			case 1:
				ai_hand = 'p';
				break;
			case 2:
				ai_hand = 's';
				break;
		}
		
		printf("%c Vs. %c\n", hand, ai_hand);
		
		if(hand == ai_hand) {
			printf("It's a draw.\n\n");
			rec.draws++;
			continue;
		} else if((hand == 'r' && ai_hand == 's') || (hand == 's' && ai_hand == 'p')
				|| (hand == 'p' && ai_hand == 'r')) {
			printf("You win this hand!\n\n");
			rec.wins++;
			continue;
		} else {
			printf("You lose this hand...\n\n");
			rec.losses++;
			continue;
		}
	}
	
	printf("Your record is W-%d/L-%d/D-%d\n", rec.wins, rec.losses, rec.draws);
	return 0;
}