/* display amount of tax witha function */
#include <stdio.h>

float Tax(float amount);

int main(void)
{
    float principle;
    
    printf("Enter amount of taxable income: ");
    scanf("%f", &principle);
    

       
    printf("Tax due: $%.2f\n", Tax(principle));
    
    return 0;
}

float Tax(float amount)
{
    float tax;
    
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
        
    return tax;
}