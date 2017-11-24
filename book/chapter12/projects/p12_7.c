/* Finds the largest and smallest elements in an array */

#include <stdio.h>

#define N 10


void max_min(int *start, int *min, int *max);

int main(void)
{
	int b[N], i, *start = b, min, max;
	
	printf("Enter %d numbers: ", N);
	for(start = b; start < b + N; start++) {
		scanf("%d", start);
	}
	start = b;
	max = min = *start;
	
	max_min(start, &min, &max);
	
	printf("Smallest: %d\n", min);
	printf("Largest: %d\n", max);
	
	return 0;
}

void max_min(int *start, int *min, int *max)
{
	int *p;
	
	for(p = start; p < start + N; p++) {
		if(*p > *max) {
			*max = *p;
		} else if(*p < *min) {
			*min = *p;
		}
	}
}