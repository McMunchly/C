/* display amount of tax */
#include <stdio.h>

int main(void)
{
    float amount, tax;
    
    printf("Enter amount of taxable income: ");
    scanf("%f", &amount);
    
    if(amount < 750.0f)
        tax = .01f * amount;
    else if(amount <= 2250.0f)
        tax = 7.5f + (.02 * (amount - 750));
    else if(amount <= 3750.0f)
        tax = 37.5f + (.03 * (amount - 2250));
    else if(amount <= 5250.0f)
        tax = 82.5f + (.04 * (amount - 3750));
    else if(amount < 7000.0f)
        tax = 142.5f + (.05 * (amount - 5250));
    else
        tax = 230.5f + (.06 * (amount - 7000));
       
    printf("Tax due: $%.2f\n",  tax);
    
    return 0;
}