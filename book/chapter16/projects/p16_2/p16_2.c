/* maintains a parts database (array version) */

#include <stdio.h>   /* printf, scanf */
#include <stdlib.h>  /* qsort         */
#include "p16_2.h"
#include "readline.h"

struct part inventory[MAX_PARTS];

int num_parts = 0; /* number of parts currently stored */

/* Prompts the user to enter and operation code,
 * then calls a function to perform the requested
 * action. Repeats until the user enters the
 * command 'q'. Prints and error message if the user
 * enters and illegal code
 */
int main(void) {
	char code;
	
	for(;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		
		while(getchar() != '\n') {	/* skips to end of line */
			;
		}
		
		switch(code) {
			case 'i':
				insert();
				break;
			case 's':
				search();
				break;
			case 'u':
				update();
				break;
			case 'p':
				print();
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
int find_part(int number) {
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
void insert(void) {
	int part_number;
	
	if(num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return;
	}
	
	printf("Enter part number: ");
	scanf("%d", &part_number);
	
	if(find_part(part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}
	
	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	num_parts++;
}

/* Prompts the user to enter a part number, then
 * looks up the part in the database. If the part
 * exists, prints the name and quantity on hand;
 * of not, prints and error message.
 */
void search(void) {
	int i, number;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if(i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
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
void update(void) {
	int i, number, change;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if(i >= 0) {
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
void print(void) {
	int i;
	
	qsort(inventory, num_parts, sizeof(struct part), compare);

	printf("Part Number	Part Name		"
			"Quantity on Hand\n");
			
	for(i = 0; i < num_parts; i++) {
		printf("%7d		%-25s%11d\n", inventory[i].number,
				inventory[i].name, inventory[i].on_hand);
	}
}

/* this function compares two part structs for qsort function */
int compare(const void *s1, const void *s2) {
	struct part *e1 = (struct part *)s1;
	struct part *e2 = (struct part *)s2;
	
    return (*e1).number - (*e2).number;
}