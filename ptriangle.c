/* creates a pascal's triangle */

#include <stdio.h>
#include <math.h>

#define MAX 9

long factorial(int n);

int main(void) {
	int limit, num, j, i;
	
	printf("Enter size of triangle (1-%d): ", MAX);
	scanf("%d", &limit);
	
	if(limit < 1) {
		printf("Too small. Resizing triangle to 1.\n");
		limit = 1;
	}else if(limit > MAX) {
		printf("Too large. Resizing triangle to %d.\n", MAX);
		limit = MAX;
	}
	
	for(num = 0; num < limit; num++) {
		for(j = 0; j <= (limit - num - 2); j++) {
			printf(" ");
		}

		for(i = 0; i <= num; i++) {
			printf("%ld ", factorial(num) / (factorial(num - i) * factorial(i)));
		}
		printf("\n");
	} 
	
	return 0;
}

long factorial(int n) {
	int i;
	long num = 1;
	
	for(i = 1; i < n; i++) {
		num = num * i;
	}

	return num;
}