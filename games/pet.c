/* take care of a virtual pet */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAME 25
#define LEVELS 10
#define EXP 50

int main(void) {

	char ch, *name;
	int i, days = 0;
	
	struct pet {
		char *name;
		int level;
		int hunger;
		int strength;
		int happiness;
	} newpet = {NULL, 1, 60, 11, 50};
	
	printf("What is your pet's name?: ");
	scanf("%s", name);
	
	newpet.name = malloc(strlen(name));
	if(newpet.name == NULL) {
		printf("-- Name is too long --\n");
		exit(EXIT_FAILURE);
	}
		
	newpet.name = name;

	/* game loop */
	for(;;) {
		printf("\n");
		newpet.hunger -= 10;
		newpet.strength -= 1;
		
		if(newpet.level < LEVELS && newpet.strength > EXP) {
			newpet.level++;
			newpet.strength = 11;
			printf("%s is so strong it grew a level!\n", newpet.name);
		} else if(newpet.level > 0 && newpet.strength <= 0) {
			newpet.level--;
			printf("%s is so weak it dropped a level...\n", newpet.name);
			newpet.strength = 11;
		}
		
		if(newpet.level < 1) {
			printf("%s was too weak and died.\n", newpet.name);
			break;
		}
		
		printf("%s is at level %d\n", newpet.name, newpet.level);
		printf("%s is %d strong.\n", newpet.name, newpet.strength);
		
		if(newpet.hunger > 150) {
			printf("%s died from overfeeding.\n", newpet.name);
			break;
		} else if(newpet.hunger > 100) {
			printf("%s is getting tubby\n", newpet.name);
		} else if(newpet.hunger <= 0) {
			printf("%s has starved to death.\n", newpet.name);
			break;
		} else {
			printf("%s is %d hungry.\n", newpet.name, newpet.hunger);
		}
		
		if(newpet.happiness <= 0) {
			printf("%s was unhappy and ran away.\n", newpet.name);
			break;
		} else if(newpet.happiness > 150) {
			printf("%s died from overstimulation.\n", newpet.name);
		} else if(newpet.happiness > 100) {
			printf("%s is getting riled up\n", newpet.name);
		} else {
			printf("%s is %d happy.\n", newpet.name, newpet.happiness);
		}

		printf("Command? (f = feed, e = exercise, p = play, n = nothing): ");
		scanf(" %c", &ch);
		
		if(ch == 'f') {
			newpet.hunger += 25;
		} else if(ch == 'e') {
			newpet.hunger -= 5;
			newpet.strength += 5;
			newpet.happiness -= 15;
		} else if(ch == 'p') {
			newpet.happiness += 25;
		} else if(ch == 'n') {
			newpet.happiness -= 10;
		} else if(ch == 'q') {
			break;
		}
		
		days++;
	}
	
	printf("%s survived for %d days and reached level %d.\n", newpet.name, days, newpet.level);
	return 0;
}