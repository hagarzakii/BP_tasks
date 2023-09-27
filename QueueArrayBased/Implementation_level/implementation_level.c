#include <stdio.h>
#include "implementation_level.h"

void createQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}

void append(queueEntry item , Queue *pq)
{
	/*if(pq->rear == MAX_QUEUE-1)
	{
		pq->rear=0;
	}
	else{
		pq->rear ++;
	} */
	pq->rear = (pq->rear + 1) % MAX_QUEUE;
	pq->entry [pq->rear] = item;
	pq->size ++;
}

void serve (queueEntry *pitem , Queue *pq)
{
	*pitem = pq->entry[pq->front];
	 pq->front = (pq->front + 1) % MAX_QUEUE;
	 pq->size --;
}

int queueEmpty (Queue *pq)
{
	return !pq->size ;
}

int queueFull(Queue *pq)
{
	return (pq->size == MAX_QUEUE);
}

int queueSize (Queue *pq)
{
	return pq->size;
}

void clearQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}

void traverseQueue(Queue *pq , void(*pf)(queueEntry))
{
	int pos ,s;
	for(pos = pq-> front , s = 0; s < pq->size ; s++)
	{
		(*pf)(pq->entry[pos]);
		pos = (pos+1) % MAX_QUEUE;
	}
}