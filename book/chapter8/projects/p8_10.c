/* calculate closest departure time */
#include <stdio.h>

int main(void)
{
    int hour, minutes, time;
    int depart[8];
    
    /* calculate the total minutes of all departure times */
    depart[0] = 8 * 60;
    depart[1] = 9 * 60 + 43;
    depart[2] = 11 * 60 + 19;
    depart[3] = 12 * 60 + 47;
    depart[4] = 14 * 60;
    depart[5] = 15 * 60 + 45;
    depart[6] = 19 * 60;
    depart[7] = 21 * 60 + 45;
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minutes);
    
    time = 60 * hour + minutes;

    if(time < depart[0] + (depart[1] - depart[0]) / 2)
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    else if(time < depart[1] + (depart[2] - depart[1]) / 2)
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    else if(time < depart[2] + (depart[3] - depart[2]) / 2)
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    else if(time < depart[3] + (depart[4] - depart[3]) / 2)
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    else if(time < depart[4] + (depart[5] - depart[4]) / 2)
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    else if(time < depart[5] + (depart[6] - depart[5]) / 2)
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    else if(time < depart[6] + (depart[7] - depart[6]) / 2)
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");  
    
    return 0;
}