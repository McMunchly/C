/* find out which date comes earlier using structs */
#include <stdio.h>

int main(void) {
	struct date {
		int day;
		int month;
		int year;
	} date1, date2;
	
    int earlier = 0;
    
    printf("Enter first date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &date1.month, &date1.day, &date1.year);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &date2.month, &date2.day, &date2.year);
    
    /* compare the year, month, and days to find the earliest one */
    if(date1.year < date2.year) {
        earlier = 1;
    } else if(date2.year < date1.year) {
        earlier = 2;
    } else {
        if(date1.month < date2.month) {
            earlier = 1;
        } else if(date2.month < date1.month) {
            earlier = 2;
        } else {
        	if(date1.day < date2.day) {
            	earlier = 1;
            } else if(date2.day < date1.day) {
            	earlier = 2;
            }
        }
    }  
    
    switch(earlier) {
        case 1:
            printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n",
            	date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
            break;
        case 2:
            printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n",
            	date2.month, date2.day, date2.year, date1.month, date1.day, date1.year);
            break;
        case 0:
            printf("The dates are the same\n");
    }
    
    return 0;
}