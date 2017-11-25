/* reformat a person's name */
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80

void reverse_name(char *name);

int main(void)
{
    char ch, first[MAX_LENGTH / 2 + 1], last[MAX_LENGTH / 2 + 1], name[MAX_LENGTH + 1];
    
    printf("Enter a first and last name: ");
	scanf(" %s %s", first, last);

	/* make it so the string is always passed first-space-last */
    strcpy(name, first);
    strcat(name, " ");
	strcat(name, last);

    reverse_name(name);
    printf("%s\n", name);
    return 0;
}

void reverse_name(char *name)
{	
	char ch = *name, *first = name;
	
	char end[5] = {',', ' ', ch, '.', '\0'};
	
	/* find the end of the first name */
    while(*name != ' ') {
    	name++;
    }
	
	/* skip ahead to the start of the last name */
	name++;
	
	/* replace the first name with last name */
    while(*name != '\0') {
    	*first++ = *name++;
    }
    /* end the string at the end of the last name */
    *first = '\0';
    
    /* concat the ending bit to the string */
    strcat(first, end);
}