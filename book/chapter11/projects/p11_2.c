/* calculate closest departure time */
#include <stdio.h>
#include <stdbool.h>

#define FLIGHTS 8

/* all departure times and corresponding lengths of flights */
int departs[FLIGHTS][2] = {{8 * 60, 136}, {9 * 60 + 43, 129}, {11 * 60 + 19, 132},
    				{12 * 60 + 47, 133}, {14 * 60, 128}, {15 * 60 + 45, 130},
    				{19 * 60, 140}, {21 * 60 + 45, 133}};
    					
void find_closest_flight(int desired_time, int *departure_time, int *arrive_time);

int main(void)
{
	bool valid = false;
    int hour, minutes;
    
    int departuretime, arrivetime;
    int *departure = &departuretime, *arrive = &arrivetime;
    
    /* check for a valid 24-hour time entry */
    do {
	    printf("Enter a 24-hour time: ");
	    scanf("%d:%d", &hour, &minutes);
    
	    if(hour < 0 || hour > 23 || minutes < 0 || minutes > 60) {
			printf("Invalid time.\n");
		} else {
			valid = true;
		}
	} while(valid != true);

	find_closest_flight(60 * hour + minutes, departure, arrive);
    
	printf("Closest departure time is %d:%.2d, arriving at %d:%.2d\n",
			departuretime / 60, departuretime % 60, arrivetime / 60, arrivetime % 60);
			
    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrive_time)
{
	int i = 0;
	
	while(i < FLIGHTS) {
		if(desired_time < departs[i][0] + (departs[i + 1][0] - departs[i][0]) / 2 || i == FLIGHTS - 1) {
			*departure_time = departs[i][0];
        	*arrive_time = departs[i][0] + departs[i][1];
        	return;
        }
        
        i++;
	}
}