#include <stdio.h>
#include "queue.h"

int main(void) {
	Queue q1, q2;

	q1 = create();
	q2 = create();
	
	push(q1, 1);
	push(q1, 2);
	push(q1, 3);
		
	printf("First element of q1: %d\n", get_first(q1));
	printf("Last element of q1: %d\n", get_last(q1));

	destroy(q1);
	push(q2, 11);
	push(q2, 22);
	push(q2, 33);
	push(q2, 44);
	push(q2, 55);
	while(!is_empty(q2)) {
		printf("Last element of q2: %d\n", get_last(q2));
		printf("Popped %d from q2\n", pop(q2));
	}
	
	make_empty(q2);
	
	if(is_empty(q2)) {
		printf("q2 is empty\n");
	} else {
		printf("q2 is not empty\n");
	}
	
	destroy(q2);
	
	return 0;
}