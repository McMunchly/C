#include <stdio.h>

#define FRACTION 4.0f / 3.0f
#define PI 3.14159f

int main(void)
{
	int radius = 10;
	
	float volume = FRACTION * PI * (radius * radius * radius);
	
	printf("Volume: %f\n", volume);
    return 0;
}