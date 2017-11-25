/* find average word length of a sentence with strings */
#include <stdio.h>

#define MAX_LENGTH 100

double compute_average_word_length(const char *sentence);
int read_line(char str[], int n);

int main(void)
{
    char sentence[MAX_LENGTH + 1];
    
    printf("Enter a sentence: ");
    
    read_line(sentence, MAX_LENGTH);

    printf("Average word length: %.1f\n", compute_average_word_length(sentence));
    
    return 0;
}

double compute_average_word_length(const char *sentence)
{
	int words = 0, length = 0;
    double sum = 0, average;
    
    while(*sentence != '\0') {
        if(*sentence != ' ' && *sentence != '\t') {
            if(length == 0) {
                words++;
            }
            length++;
        } else {
            sum += length;
            length = 0;
        }

        sentence++;
    }
    sum += length;
    
    return sum / words;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while((ch = getchar()) != '\n') {
		if(i < n) {
			str[i++] = ch;
		}
	}
		
	str[i] = '\0';
	
	return i;
}