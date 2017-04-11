/* calculate closest departure time */
#include <stdio.h>

int main(void)
{
    int hour, minutes, time;
    int depart1, depart2, depart3, depart4, depart5, depart6, depart7, depart8;
    
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
    
    time = 60 * hour + minutes;

    if(time < depart1 + (depart2 - depart1) / 2)
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    else if(time < depart2 + (depart3 - depart2) / 2)
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    else if(time < depart3 + (depart4 - depart3) / 2)
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    else if(time < depart4 + (depart5 - depart4) / 2)
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    else if(time < depart5 + (depart6 - depart5) / 2)
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    else if(time < depart6 + (depart7 - depart6) / 2)
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    else if(time < depart7 + (depart8 - depart7) / 2)
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");  
    
    return 0;
}