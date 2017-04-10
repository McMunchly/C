/* create a square of 16 numbers */
#include <stdio.h>

int main(void)
{
    int one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen;
    
    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &one, &two, &three, &four, &five, &six, &seven, &eight, &nine, &ten, &eleven, &twelve, &thirteen, &fourteen, &fifteen, &sixteen);
    
    printf("%2d %2d %2d %2d\n", one, two, three, four);
    printf("%2d %2d %2d %2d\n", five, six, seven, eight);
    printf("%2d %2d %2d %2d\n", nine, ten, eleven, twelve);
    printf("%2d %2d %2d %2d\n", thirteen, fourteen, fifteen, sixteen);
    
    printf("Row sums: %2d %2d %2d %2d\n", one + five + nine + thirteen, two + six + ten + fourteen, three + seven + eleven + fifteen, four + eight + twelve + sixteen);
    
    printf("Column sums: %2d %2d %2d %2d\n", one + two + three + four, five + six + seven + eight, nine + ten + eleven + twelve, thirteen + fourteen + fifteen + sixteen);
    
    printf("Diagonal sums: %2d %2d\n", one + six + eleven + sixteen, four + seven + ten + thirteen
    );
    return 0;
}