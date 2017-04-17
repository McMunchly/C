/* checks if two words are anagrams with functions*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void)
{
    int i, alpha[26] = {0}, alpha2[26] = {0};
    
    printf("Enter first word: ");
    read_word(alpha);
    
    printf("Enter second word: ");
    read_word(alpha2);
     
    printf("The words are");
    
    if(equal_array(alpha, alpha2) == false)
        printf(" not");
        
    printf(" anagrams\n");
    return 0;
}

void read_word(int counts[26])
{
    char ch;
    ch = getchar();
    
    while(ch != '\n')
    {
        if(isalpha(ch))
        {
            ch = tolower(ch);
            counts[ch - 'a'] += 1;
        }
        
        else
        {
            printf("you must only input alphabetical characters\n");
            exit(0);
        }
        
        ch = getchar();
    }
}

bool equal_array(int counts1[26], int counts2[26])
{
    int i;
    
    for(i = 0; i < 26; i++)
    {
        if(counts1[i] != counts2[i])
        {
            return false;
        }
    }
    
    return true;
}