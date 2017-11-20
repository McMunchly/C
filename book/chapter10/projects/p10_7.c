/* displays numbers in digital format */

#include <stdio.h>

#define MAX_DIGITS 10

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0},
							 {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
							 {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
							 {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0},
							 {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
		 						 							 
int digits[4][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
	int position = 0;
	char ch;
	
	clear_digits_array();
		
	printf("Enter a number: ");

	while((ch = getchar()) != '\n' && position < 10) {
		switch(ch) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				process_digit((int)ch - 48, position * 4);
				position++;
				break;
		}
	}

	print_digits_array();
	
	return 0;
}

void clear_digits_array(void)
{
	int i, j;
	
	for(i = 0; i < 4; i++) {
		for(j = 0; j < MAX_DIGITS * 4; j++) {
			digits[i][j] = 0;
		}
	}
}

void process_digit(int digit, int position)
{	
	/* first row */
	digits[0][position] = 0;
	
	if(segments[digit][0] == 0) {
		digits[0][position + 1] = 0;
	} else {
		digits[0][position + 1] = 1;
	}
	
	digits[0][position + 2] = 0;
	digits[0][position + 3] = 0;
	
	/* second row */
	if(segments[digit][5] == 0) {
		digits[1][position] = 0;
	} else {
		digits[1][position] = 2;
	}
	
	if(segments[digit][6] == 0) {
		digits[1][position + 1] = 0;
	} else {
		digits[1][position + 1] = 1;
	}
	
	if(segments[digit][1] == 0) {
		digits[1][position + 2] = 0;
	} else {
		digits[1][position + 2] = 2;
	}
	
	digits[1][position + 3] = 0;
	
	/* third row */
	if(segments[digit][4] == 0) {
		digits[2][position] = 0;
	} else {
		digits[2][position] = 2;
	}
	
	if(segments[digit][3] == 0) {
		digits[2][position + 1] = 0;
	} else {
		digits[2][position + 1] = 1;
	}
	
	if(segments[digit][2] == 0) {
		digits[2][position + 2] = 0;
	} else {
		digits[2][position + 2] = 2;
	}
	
	digits[2][position + 3] = 0;
}

void print_digits_array(void)
{
	int i, j;
	
	for(i = 0; i < 4; i++) {
		for(j = 0; j < MAX_DIGITS * 4; j++) {
			if(digits[i][j] == 0) {
				printf("%c", ' ');
			} else if(digits[i][j] == 1) {
				printf("%c", '_');
			} else {
				printf("%c", '|');
			}
		}
		
		printf("\n");
	}
}