/* compute a factorial with a bunch of different data types */
#include <stdio.h>

int main(void)
{
    short number;
    int numberi;
    long numberl;
    float numberf;
    double numberd;
    long double numberld;
    
    int i;
    int storage;
    printf("Enter a positive integer: ");
    scanf("%hd", &number);
    
    numberi = 1;
    numberl = 1;
    numberf = 1.0f;
    numberd = 1.0;
    numberld = 1.0;
        
    storage = number;
    i = storage;
    number = 1;
    
    while(i > 0)
    {
        number *= i;
        i--;
    }
    printf("factorial of %d (short): %hd\n", storage, number);
        
    i = storage;
    
    while(i > 0)
    {
        numberi *= i;
        i--;
    }
    printf("factorial of %d (int): %d\n", storage, numberi);
        
    i = storage;
    
    while(i > 0)
    {
        numberl *= i;
        i--;
    }
    printf("factorial of %d (long): %ld\n", storage, numberl);
    
    i = storage;
    
    while(i > 0)
    {
        numberf *= i;
        i--;
    }
    printf("factorial of %d (float): %f\n", storage, numberf);
    
    i = storage;
    
    while(i > 0)
    {
        numberd *= i;
        i--;
    }
    printf("factorial of %d (double): %f\n", storage, numberd);
    
    i = storage;
    
    while(i > 0)
    {
        numberld *= i;
        i--;
    }
    printf("factorial of %d (long double): %Lf\n", storage, numberld);
    
    return 0;
}