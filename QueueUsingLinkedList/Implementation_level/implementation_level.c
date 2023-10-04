#include <stdio.h>
#include <stdlib.h>
#include "implementation_level.h"

void createList(List *pl)
{
	pl->head = NULL;
	pl->lastPos = NULL;
	pl->size = 0;
}

int listFull(List *pl)
{
	return 0;
}

int listEmpty(List *pl)
{
	return (pl->size==0);
}

int insertList(listEntry item , List *pl)
{
	ListNode *p ;
	if(p = (ListNode*)malloc(sizeof(ListNode))){
	p->entry = item;
	p->next =NULL;
	if(pl->size == 0)
	{
		pl->head = p;
		pl->lastPos = pl->head;
	}
	else
	{
		pl->lastPos->next = p;
		pl->lastPos = p;
	}
	pl->size ++;
	return 1;
	}
	else{
		return 0;
	}
}

void deleteList(listEntry *pitem , List *pl)
{
	ListNode *tmp ;
	*pitem = pl->head->entry;
	tmp = pl->head->next;
	free(pl->head);
	pl->head = tmp;
	if(pl->size == 1)
	{
		pl->lastPos = pl->head;
	}
	pl->size --;
}

void destroyList(List *pl)
{
	ListNode *q;
	while(pl->head)
	{
		q = pl-> head->next;
		free(pl->head);
		pl->head = q;
	}
	pl->size = 0;
}

void retrieveList(int p ,listEntry *pitem , List *pl)
{
	ListNode *q ;
	q = pl->head;
	for(int i = 0 ; i < p ; i ++)
	{
		q=q->next;
	}
	*pitem = q->entry;
}

int listSize(List *pl)
{
	return pl->size ;
}

void replaceList(int p ,listEntry item , List *pl)
{
	ListNode *q ;
	q = pl->head;
	for(int i = 0 ; i < p ; i ++)
	{
		q=q->next;
	}
	 q->entry = item;
}

void traverseList(List*pl , void (*pf)(listEntry item))
{
	ListNode *p = pl->head;
	while(p){
		(*pf)(p->entry);
		p = p->next;
	}
}