/* calculate closest departure time using structs*/
#include <stdio.h>

#define FLIGHTS 8
int main(void) {
	struct flight {
		int depart_hour;
		int depart_min;
		int arrive_hour;
		int arrive_min;
	} flights[FLIGHTS] = {{8, 0, 10, 16},
						  {9, 43, 11, 52},
    					  {11, 19, 1, 31},
    					  {12, 47, 3, 0},
    					  {2, 0, 4, 8},
    					  {3, 45, 5, 55},
    					  {7, 0, 9, 20},
						  {9, 45, 11, 58}};
	
    int hour, minutes, time, i;
    int depart1, depart2, depart3, depart4, depart5, depart6, depart7, depart8;
    char *meridiem_d = "a.m", *meridiem_a = "a.m.";

    /* calculate the total minutes of all departure times */
    depart1 = 8 * 60;
    depart2 = 9 * 60 + 43;
    depart3 = 11 * 60 + 19;
    depart4 = 12 * 60 + 47;
    depart5 = 14 * 60;
    depart6 = 15 * 60 + 45;
    depart7 = 19 * 60;
    depart8 = 21 * 60 + 45;
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minutes);
    
    if(hour < 0 || hour > 23 || minutes < 0 || minutes > 59) {
    	printf("Time entered is not valid\n");
    	return 0;
    }
    
    time = 60 * hour + minutes;

    if(time < depart1 + (depart2 - depart1) / 2)
        i = 0;
    else if(time < depart2 + (depart3 - depart2) / 2)
        i = 1;
    else if(time < depart3 + (depart4 - depart3) / 2)
        i = 2;
    else if(time < depart4 + (depart5 - depart4) / 2)
        i = 3;
    else if(time < depart5 + (depart6 - depart5) / 2)
        i = 4;
    else if(time < depart6 + (depart7 - depart6) / 2)
        i = 5;
    else if(time < depart7 + (depart8 - depart7) / 2)
        i = 6;
    else
        i = 7; 
        
        if(i > 2) {
        	meridiem_a = "p.m.";
        }
        if(i > 3) {
        	meridiem_d = "p.m.";
        }
        printf("Closest departure time is %d:%.2d %s, arriving at %d:%.2d %s\n",
        	flights[i].depart_hour, flights[i].depart_min, meridiem_d, 
        	flights[i].arrive_hour, flights[i].arrive_min, meridiem_a);  
    
    return 0;
}