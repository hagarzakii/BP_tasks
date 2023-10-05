#include <stdio.h>
#include <stdlib.h>
#include "implementation_level.h"

void createQueue(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}

int append(queueEntry item , Queue *pq)
{
	queueNode *pn = (queueNode*) malloc(sizeof(queueNode));
	if(!pn)
	{
		return 0 ;
	}
	else{
	pn->next = NULL;
	pn->entry = item;
	if(!pq->rear)
	{
		pq->front = pn;
	}else{
	pq->rear->next = pn;
	}
	pq->rear = pn;
	pq->size ++;
	return 1;
	}
}

void serve (queueEntry *pitem , Queue *pq)
{
	queueNode *pn = pq->front;
	*pitem = pn->entry;
	pq->front = pn->next;
	free(pn);
	if(!pq->front)
	{
		pq->rear = NULL;
	}
	pq->size --;
}

int queueEmpty (Queue *pq)
{
	return !pq->front ;
	// !pq->rear || pq->size == 0
}

int queueFull(Queue *pq)
{
	return 0;
}

int queueSize (Queue *pq)
{
	return pq->size;
}

void clearQueue(Queue *pq)
{
	while(pq->front)
	{
		pq->rear = pq->front->next;
		free(pq->front);
		pq->front = pq->rear;
	}
	pq->size = 0;
}

void traverseQueue(Queue *pq , void(*pf)(queueEntry))
{
	queueNode *pn;
	for(pn = pq->front; pn ; pn = pn->next)
	{
		(*pf)(pn->entry);
	}
}