/* calulates loan balance for three months */
#include <stdio.h>

int main(void)
{
    float loan, interest, payment;
    int number, i;
    
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    interest = (interest * .01f) / 12.0f;
    printf("Enter monthly payment: ");
    scanf("%f", &payment);
    printf("Enter number of payments: ");
    scanf("%d", &number);
    
    for(i = 0; i < number && loan >= 0.0f; i++)
    {
        loan = loan - payment + (loan * interest);
        
        printf("Balance remaining after %d", i);
        
        switch(i)
        {
            case 1:
                printf("st");
                break;
            case 2:
                printf("nd");
                break;
            case 3:
                printf("rd");
                break;
            default:
                printf("th");
                break;
        }
        
        printf(" payment: $%.2f\n", loan);
    }
    
    return 0;
}