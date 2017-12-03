/* reformats a date using an array of pointers to strings */

#include <stdio.h>

int main(void)
{
	char *months[] = {"January", "February", "March", "April", "May", "June",
						"July", "August", "September", "October", "November", "December"};
	int day, month, year;
	
	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);
	
	if(month > 12) {
		printf("Invalid month\n");
		return 0;
	}
	
	printf("You entered the date %s %.2d, %.4d\n", months[month - 1], day, year);
	
	return 0;
}