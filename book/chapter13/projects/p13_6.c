/* Checks planet names */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_PLANETS 8

int string_compare(const char *s, const char *s2);

int main(int argc, char *argv[])
{
	char *planets[] = {"Mercury", "Venus", "Earth", "Mars",
						"Jupiter", "Saturn", "Uranus", "Neptune"};
						
	int i, j;
	
	for(i = 1; i < argc; i++) {
		for(j = 0; j < NUM_PLANETS; j++) {
			if(string_compare(argv[i], planets[j])) {
				printf("%s is planet %d\n", argv[i], j + 1);
				break;
			}
		}
		
		if(j == NUM_PLANETS) {
			printf("%s is not a planet\n", argv[i]);
		}
	}
	
	return 0;
}

int string_compare(const char *s, const char *s2)
{
	int i;
	
	for(i = 0; tolower(s[i]) == tolower(s2[i]); i++) {
		if(s[i] == '\0') {
			return 1;
		}
	}
	
	return 0;
}