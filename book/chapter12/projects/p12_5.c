/* reverse the words in a sentence with pointers */
#include <stdio.h>
#include <ctype.h>

#define SIZE 99

int main(void)
{
    char c, ch[SIZE] = {' '}, *p = ch, *p2;
    
    printf("Enter a sentence: ");
    
    c = getchar();

    while(c != '\n') {
        if(c == '.' || c == '\?' || c == '!')
            break;
        
        *p = c;
        p++;
        c = getchar();
    }
   
   /* record period/question mark/exclamation, or just a newline */
    *p = c;
    
    printf("Reversal of sentence:");
    
    for(p = ch + SIZE - 1; p >= ch; p--) {
        if(*p == ' '|| p == ch) {
            if(p == ch) {
                putchar(' ');
            }

            for(p2 = p; ; p2++)  {
                *p2 = tolower(*p2);
                
                if(p2 != p && (*p2 == ' ' || *p2 == '\n' || *p2 == c)) {
                    break;
                }
                    
                putchar(*p2);
            }
        }
    }
    
    /* display period/question mark/exclamation, or just a new line */
    printf("%c\n", c);
    
    return 0;
}