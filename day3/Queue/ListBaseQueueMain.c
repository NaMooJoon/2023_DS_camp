#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
	/* queue create & init */
	Queue q;
	queue_init(&q);

	/* enqueue 5 data */
	Enqueue(&q, 1);  Enqueue(&q, 2);
	Enqueue(&q, 3);  Enqueue(&q, 4);
	Enqueue(&q, 5);

	/* print all data */
	while(!q_is_empty(&q))
		printf("%d ", dequeue(&q)); 

	return 0;
}