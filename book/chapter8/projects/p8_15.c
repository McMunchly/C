/* encrypt a message with the caesar cipher */
#include <stdio.h>

int main(void)
{
    char ch[80] = {' '};
    int i = 0, shift;
    
    printf("Enter message to be encrypted: ");
    ch[i] = getchar();

    while(ch[i] != '\n')
        ch[++i] = getchar();
    
    printf("Enter shift amount: ");
    scanf("%d", &shift);
    
    printf("Encrypted message: ");

    for(int i = 0; i < 80; i++)
    {
        if((ch[i] >= 'A' && ch[i] <= 'Z'))
            ch[i] = (((ch[i] - 'A') + shift) % 26) + 'A';
            
        else if(ch[i] >= 'a' && ch[i] <= 'z')
            ch[i] = ((ch[i] - 'a') + shift) % 26 + 'a';

        putchar(ch[i]);
    }
    
    return 0;
}