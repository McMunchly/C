/* encrypt a message with the caesar cipher */
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80
void encrypt(char *message, int shift);

int main(void)
{
    char ch[MAX_LENGTH + 1], *p = ch;
    int shift;
    
    printf("Enter message to be encrypted: ");

	/* read characters until the string is full, or a newline is reached */
    while((*p = getchar()) != '\n' && p < ch + MAX_LENGTH) {
        p++;
    }
    
    /* null-terminate the resulting string */
    *p = '\0';
    
    printf("Enter shift amount: ");
    scanf("%d", &shift);
    
	encrypt(ch, shift);
        
    printf("Encrypted message: %s\n", ch);
    
    return 0;
}

void encrypt(char *message, int shift)
{
	/* go through each character and shift it the chosen amount */
    while(*message != '\0') {
    	/* capital letters */
        if((*message >= 'A' && *message <= 'Z')) {
            *message = ((*message - 'A') + shift) % 26 + 'A';
        }
            
        /* lower case letters */
        else if(*message >= 'a' && *message <= 'z') {
            *message = ((*message - 'a') + shift) % 26 + 'a';
        }
        
        message++;
    }
}