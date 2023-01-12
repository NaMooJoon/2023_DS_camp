#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void queue_init(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int q_is_empty(Queue * pq)
{
	if(pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void enqueue(Queue * pq, Data data)
{
	Node * new_node = (Node*)malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = data;

	if(q_is_empty(pq))
	{
		pq->front = new_node;
		pq->rear = new_node;
	}
	else
	{
		pq->rear->next = new_node;
		pq->rear = new_node;
	}
}

Data dequeue(Queue * pq)
{
	Node * delNode;
	Data retData;

	if(q_is_empty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return retData;
}

Data q_peek(Queue * pq)
{
	if(q_is_empty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}