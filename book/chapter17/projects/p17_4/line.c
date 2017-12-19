#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60
#define WORD_LENGTH 50

int line_len = 0;
int num_words = 0;

struct wordnode {
	char word[WORD_LENGTH + 1];
	struct wordnode *next;
};

struct wordnode *line = NULL;

void clear_line(void) {

	struct wordnode *cur;
	
	for(cur = line; cur != NULL;) {
		cur = cur->next;
		free(cur);
	}
	
	line = NULL;

	line_len = 0;
	num_words = 0;
}

void add_word(const char *word) {
	struct wordnode *cur, *prev, *new_node;

	new_node = malloc(sizeof(struct wordnode));

	strcpy(new_node->word, word);

	strcat(new_node->word, " ");
	strcat(new_node->word, "\0");
	line_len++;
	
	for(cur = line, prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
		;
	}
	
	new_node->next = cur;
		
	if(prev == NULL) {
		line = new_node;
	} else {
		prev->next = new_node;
	}


	line_len += strlen(word);
	num_words++;

}

int space_remaining(void) {
	return MAX_LINE_LEN - line_len;
}


void write_line(void) {
	int extra_spaces, spaces_to_insert, i, j;

	extra_spaces = space_remaining();
	num_words--;

	for(; line != NULL; line = line->next) {
		printf("%s", line->word);
		
		if(line->next != NULL) {
			spaces_to_insert = extra_spaces / num_words;

			for(j = 1; j <= spaces_to_insert; j++) {
				putchar(' ');
			}
			
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}

	putchar('\n');
}

void flush_line(void) {

	if(line_len > 0) {
		for(; line != NULL; line = line->next) {
			puts(line->word);
		}
	}
}