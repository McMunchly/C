/* calulates loan balance for three months */
#include <stdio.h>

int main(void)
{
    float loan, interest, payment;
    
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    interest = (interest * .01f) / 12.0f;
    printf("Enter monthly payment: ");
    scanf("%f", &payment);
    
    loan = loan - payment + (loan * interest);
    printf("Balance remaining after first payment: $%.2f\n", loan);
    loan = loan - payment + (loan * interest);
    printf("Balance remaining after second payment: $%.2f\n", loan);
    loan = loan - payment + (loan * interest);
    printf("Balance remaining after third payment: $%.2f\n", loan);
    
    return 0;
}