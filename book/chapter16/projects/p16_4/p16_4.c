/* maintains a parts database (array version) */

#include <stdio.h>   /* printf, scanf */
#include <stdlib.h>  /* qsort         */
#include "p16_4.h"
#include "readline.h"

/* Prompts the user to enter and operation code,
 * then calls a function to perform the requested
 * action. Repeats until the user enters the
 * command 'q'. Prints and error message if the user
 * enters and illegal code
 */
int main(void) {
	char code;
	
	struct part inventory[MAX_PARTS];

	int num_parts = 0; /* number of parts currently stored */

	for(;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		
		while(getchar() != '\n') {	/* skips to end of line */
			;
		}
		
		switch(code) {
			case 'i':
				insert(inventory, &num_parts);
				break;
			case 's':
				search(inventory, num_parts);
				break;
			case 'u':
				update(inventory, num_parts);
				break;
			case 'p':
				print(inventory, num_parts);
				break;
			case 'q':
				return 0;
			default:
				printf("Illegal code\n");
		}
		
		printf("\n");
	}
}

/* Looks up a part number in the inventory
 * array. Returns the array index if the part
 * number is found; otherwise, returns -1
 */
int find_part(const struct part inventory[], int num_parts, int number) {
	int i;
	
	for(i = 0; i < num_parts; i++) {
		if(inventory[i].number == number) {
			return i;
		}
	}
	
	return -1;
}

/* Prompts the user for information about a new
 * part and then inserts the part into the
 * database. Prints an error message and returns
 * prematurely if the part already exists or the
 * database is full.
 */
void insert(struct part inventory[], int *num_parts) {
	int part_number;
	
	if(*num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return;
	}
	
	printf("Enter part number: ");
	scanf("%d", &part_number);
	
	if(find_part(inventory, *num_parts, part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}
	
	inventory[*num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[*num_parts].name, NAME_LEN);
	printf("Enter price: ");
	scanf("%f", &inventory[*num_parts].price);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[*num_parts].on_hand);
	*num_parts += 1;
}

/* Prompts the user to enter a part number, then
 * looks up the part in the database. If the part
 * exists, prints the name and quantity on hand;
 * of not, prints and error message.
 */
void search(const struct part inventory[], int num_parts) {
	int i, number;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(inventory, num_parts, number);
	if(i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Price: %.2f\n", inventory[i].price);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	} else {
		printf("Part not found.\n");
	}
}

/* Prompts the user to enter a part number.
 * Prints an error message if the part doesn't
 * exist; otherwise, prompts the user to enter
 * change in quantity on hand and updates the
 * database
 */
void update(struct part inventory[], int num_parts) {
	int i, number, change;
	float fchange;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(inventory, num_parts, number);
	if(i >= 0) {
		printf("Enter change in price: ");
		scanf("%f", &inventory[i].price);
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	} else {
		printf("Part not found.\n");
	}
}

/* Prints a listing of all parts in the database,
 * showing the part number, part name, and
 * quantity on hand. Parts are printed in the
 * order in which they were entered into the
 * database
 */
void print(struct part inventory[], int num_parts) {
	int i;
	
	qsort(inventory, num_parts, sizeof(struct part), compare);

	printf("Part Number	Part Name           Price       "
			"Quantity on Hand\n");
			
	for(i = 0; i < num_parts; i++) {
		printf("%7d		%-20s%.2f%15d\n", inventory[i].number,
				inventory[i].name, inventory[i].price, inventory[i].on_hand);
	}
}

/* this function compares two part structs for qsort function */
int compare(const void *s1, const void *s2) {
	struct part *e1 = (struct part *)s1;
	struct part *e2 = (struct part *)s2;
	
    return (*e1).number - (*e2).number;
}