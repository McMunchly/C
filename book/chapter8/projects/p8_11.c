/* translates an alphabetic phone number into numeric form with arrays */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch, num[15];
    int i;
    
    printf("Enter phone number: ");
    ch = getchar();
    
    for(i = 0; ch != '\n'; i++)
    {   
        ch = toupper(ch);
        
        switch(ch)
        {
            case 'A': case 'B': case 'C':
                ch = '2';
                break;
            case 'D': case 'E': case 'F':
                ch = '3';
                break;
            case 'G': case 'H': case 'I':
                ch = '4';
                break;
            case 'J': case 'K': case 'L':
                ch = '5';
                break;
                case 'M': case 'N': case 'O':
                ch = '6';
                break;
            case 'P': case 'R': case 'S':
                ch = '7';
                break;
            case 'T': case 'U': case 'V':
                ch = '8';
                break;
            case 'W': case 'X': case 'Y':
                ch = '9';
                break;
        }
        num[i] = ch;    
        ch = getchar();
    }
    printf("In numeric form: ");
    for(i = 0; i < 15; i++)
    {  
        printf("%c", num[i]);
    }
    printf("\n");
    
    return 0;
}