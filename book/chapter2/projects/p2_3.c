/* find the radius of any sphere */
#include <stdio.h>

#define FRACTION 4.0f / 3.0f
#define PI 3.14159f

int main(void)
{
	float radius;
	printf("Enter the radius of a sphere: ");
	scanf("%f", &radius);
	
	float volume = FRACTION * PI * (radius * radius * radius);
	
	printf("Volume: %f\n", volume);
    return 0;
}