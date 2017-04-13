/* evaluate an arithmetic expression */
#include <stdio.h>

int main(void)
{
    float sum = 0.0f, cur;
    char c;
    int i = 0;
    
    printf("Enter an expression: ");
    

            
    while(c != '\n')
    {        
        scanf("%f", &cur);
          
        if(i == 0)
            sum = cur;
          
        switch(c)
        {
            case '+':
                sum += cur;
                break;
            case '-':
                sum -= cur;
                break;
            case '*':
                sum *= cur;
                break;
            case '/':
                sum /= cur;
                break;
        }
        
        c = getchar();
        
        i++;
    }
    
    printf("Value of expression: %.1f\n", sum);
    return 0;
}