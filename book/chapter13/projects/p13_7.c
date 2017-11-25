/* print english word for a two-digit number with strings */
#include <stdio.h>

int main(void)
{
    int number;
    
    char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
					"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
		
	char *ones[] = {"-one", "-two", "-three", "-four", "-five",
					"-six", "-seven", "-eight", "-nine"};
					
	char *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty",
					"seventy", "eighty", "ninety"};	
			
    printf("Enter a two-digit number: ");
    scanf("%d", &number);
    
    if(number < 10 || number > 99) {
        printf("Invalid number\n");
        return 0;
    }
    
    printf("You entered the number ");

    if(number / 10 == 1) {
        printf("%s.\n", teens[number % 10]);
    } else {
        printf("%s", tens[(number / 10) - 2]);
        printf("%s.\n", ones[(number % 10) - 1]);
    }
    
    return 0;
}