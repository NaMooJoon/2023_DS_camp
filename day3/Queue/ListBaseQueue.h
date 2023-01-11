#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _lQueue
{
	Node * front;
	Node * rear;
} LQueue;

typedef LQueue Queue;

void queue_init(Queue * pq);
int q_is_empty(Queue * pq);

void enqueue(Queue * pq, Data data);
Data dequeue(Queue * pq);
Data q_peek(Queue * pq);

#endif



