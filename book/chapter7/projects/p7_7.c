/* do arithmetic between two fractions */
#include <stdio.h>

int main(void)
{
    int num, denom, num2, denom2, temp, n, m, numr, denomr;
    char operator;
    
    printf("Enter two fractions separated by an arithmetic operator: ");
    scanf("%d/%d%c%d/%d", &num, &denom, &operator, &num2, &denom2);
    
    printf("%d / %d %c %d / %d\n", num, denom, operator, num2, denom2);
    
    switch(operator)
    {
        case '*':
            numr = num * num2;
            denomr = denom * denom2;
            printf("Multiplied: %d/%d\n", numr, denomr);
            break;
        case '+':
            numr = num * denom2 + num2 * denom;
            denomr = denom * denom2;
            printf("Added: %d/%d\n", numr, denomr);
            break;
    }
    
    n = numr;
    m = denomr;
    
    while(n != 0)
    {   
        temp = m % n;
        m = n;
        n = temp;
    }
    
    printf("In lowest terms: %d/%d\n", numr / m, denomr / m);
    return 0;
}