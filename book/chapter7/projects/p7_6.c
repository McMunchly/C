/* finds the size of different types */
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
    
    printf("size of char: %lu\n", sizeof(c));
    printf("size of short int: %lu\n", sizeof(s));
    printf("size of int: %lu\n", sizeof(i));
    printf("size of unsigned int: %lu\n", sizeof(u));
    printf("size of long int: %lu\n", sizeof(l));
    printf("size of unsigned long int: %lu\n", sizeof(ul));
    printf("size of float: %lu\n", sizeof(f));
    printf("size of double: %lu\n", sizeof(d));
    printf("size of long double: %lu\n", sizeof(ld));
    
    return 0;
}