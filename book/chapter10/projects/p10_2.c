/* Classifies a poker hand */

#include <stdbool.h>	/* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
bool straight, flush, four, three;
int pairs;	/* can be 0, 1, 2 */

/* prototypes */
void read_cards(int num_in_rank[], int num_in_suit[]);
void analyze_hand(int num_in_rank[], int num_in_suit[]);
void print_result(void);

/*
 * Calls read_cards, analyze_hand, and print_result repeatedly
 */
int main(void)
{
	int num_in_rank[NUM_RANKS];
	int num_in_suit[NUM_SUITS];

 	for(;;) {
 		read_cards(num_in_rank, num_in_suit);
 		analyze_hand(num_in_rank, num_in_suit);
 		print_result();
 	}
}
 
/*
 * Reads the cards into the external variables num_in_rank
 * and num_in_suit; checks for bad cards and duplicates																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																
 */
void read_cards(int num_in_rank[], int num_in_suit[])
{
	bool card_exists[NUM_RANKS][NUM_SUITS];
 	char ch, rank_ch, suit_ch;
 	int rank, suit;
 	bool bad_card;
 	int cards_read = 0;
 	
 	for(rank = 0; rank < NUM_RANKS; rank++) {
 		num_in_rank[rank] = 0;
 		
 		for(suit = 0; suit < NUM_SUITS; suit++) {
 			num_in_suit[suit] = 0;
 			card_exists[rank][suit] = false;
 		}
 	}
 	
 	while(cards_read < NUM_CARDS) {
 		bad_card = false;
 		
 		printf("Enter a card: ");

 		rank_ch = getchar();
 		switch(rank_ch) {
 			case '0':
 				exit(EXIT_SUCCESS);
 			case '2': case '3': case '4': case '5':
 			case '6': case '7': case '8': case '9':
 				rank = (int)rank_ch - 50;
 				break;
 			case 't': case 'T':
 				rank = 8;
 				break;
 			case 'j': case 'J':
 				rank = 9;
 				break;
 			case 'q': case 'Q':
 				rank = 10;
 				break;
 			case 'k': case 'K':
 				rank = 11;
 				break;
 			case 'a': case 'A':
 				rank = 12;
 				break;
 			default:
 				bad_card = true;
 		}
 		
 		suit_ch = getchar();
 		
 		switch(suit_ch) {
 			case 'c': case 'C':
 				suit = 0;
 				break;
 			case 'd': case 'D':
 				suit = 1;
 				break;
 			case 'h': case 'H':
 				suit = 2;
 				break;
 			case 's': case 'S':
 				suit = 3;
 				break;
 			default:
 				bad_card = true;
 		}
 		
 		while((ch = getchar()) != '\n') {
 			if(ch != ' ') {
 				bad_card = true;
 			}
 		}
 			
 		if(bad_card) {
 			printf("Bad card; ignored.\n");
 		} else if(card_exists[rank][suit]) {
 			printf("Duplicate card; ignored.\n");
 		} else {
 			num_in_rank[rank]++;
 			num_in_suit[suit]++;
 			card_exists[rank][suit] = true;
 			cards_read++;
 		}
 	}
}
 	
/*
 * Determines the result of the hand																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																															
 */
void analyze_hand(int num_in_rank[], int num_in_suit[])
{
 	int num_consec = 0;
 	int rank, suit;
 	
 	straight = false;
 	flush = false;
 	four = false;
 	three = false;
 	pairs = 0;
 	
 	/* check for flush */
 	for(suit = 0; suit < NUM_SUITS; suit++) {
 		if(num_in_suit[suit] == NUM_CARDS) {
 			flush = true;
 		}
 	}
 	
 	/* check for straight */
 	rank = 0;
 	while(num_in_rank[rank] == 0) {
 		rank++;
 	}
 	
 	for(; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++) {
 		num_consec++;
 	}
 	
 	if(num_consec == NUM_CARDS) {
 		straight = true;
 		return;
 	}
 	
 	/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
 	for(rank = 0; rank < NUM_RANKS; rank++) {
 		if(num_in_rank[rank] == 4) { 
 			four = true;
 		}
 		if(num_in_rank[rank] == 3) { 
 			three = true;
 		}
 		if(num_in_rank[rank] == 2) { 
 			pairs++;
 		}
	}
}

/*
 * Prints the classification of the hand																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																															
 */
void print_result(void)
{
 	if(straight && flush) {
 		printf("Straight Flush");
 	} else if(four) {
 		printf("Four of a kind");
 	} else if(three && pairs == 1) {
 		printf("Full House");
 	} else if(flush) {
 		printf("Straight");
 	} else if(three) {
 		printf("Three of a kind");
 	}  else if(pairs == 2) {
 		printf("Two pairs");
 	}  else if(pairs == 1) {
 		printf("Pair");
 	} else {
 		printf("High card");
 	}
 	
	printf("\n\n");
}