#ifndef P17_2_H
#define P17_2_H

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int compare(const void *s1, const void *s2);

#endif
