/* find the smallest and largest words */

#include <stdio.h>
#include <string.h>

#define MSG_LEN 20

int main(void) {
	char msg_str[MSG_LEN + 1], smallest[MSG_LEN + 1], largest[MSG_LEN + 1];
	
	printf("Enter word: ");
	scanf("%s", msg_str);
	
	strcpy(smallest, msg_str);
	strcpy(largest, msg_str);
	
	while(strlen(msg_str) != 4) {	
		printf("Enter word: ");
		scanf("%s", msg_str);
		
		if(strcmp(msg_str, smallest) < 0) {
			strcpy(smallest, msg_str);
		} else if(strcmp(msg_str, largest) > 0) {
			strcpy(largest, msg_str);
		}
	}
	
	printf("Smallest word: %s\n", smallest);
	printf("Largest word: %s\n", largest);
	
	return 0;
}