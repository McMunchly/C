/* finds the size of types */
#include <stdio.h>

int main(void)
{
    char c;
    short int s;
    int i;
    unsigned int u;
    long int l;
    unsigned long int ul;
    float f;
    double d;
    long double ld;
    
    printf("%lu\n", sizeof(c));
    printf("%lu\n", sizeof(s));
    printf("%lu\n", sizeof(i));
    printf("%lu\n", sizeof(u));
    printf("%lu\n", sizeof(l));
    printf("%lu\n", sizeof(ul));
    printf("%lu\n", sizeof(f));
    printf("%lu\n", sizeof(d));
    printf("%lu\n", sizeof(ld));
    
    return 0;
}