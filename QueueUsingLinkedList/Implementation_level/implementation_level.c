#include <stdio.h>
#include <stdlib.h>
#include "implementation_level.h"

void createList(List *pl)
{
	pl->head = NULL;
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

int insertList(int pos ,listEntry item , List *pl)
{
	ListNode *p ;
	int i;
	if(p = (ListNode*)malloc(sizeof(ListNode))){
	p->entry = item;
	p->next = NULL;
	if(pos == 0)
	{
		p->next = pl->head;
		pl->head = p;
		pl->currentPos = 0;
		pl->current = pl->head;
	}
	else
	{
		if(pos <= pl->currentPos)
		{
			pl->currentPos = 0;
			pl->current = pl->head;
		}
		for(;pl->currentPos != pos-1 ; pl->currentPos++)
		{
			pl->current = pl->current->next;
		}
		p->next = pl->current->next;
		pl->current->next =p;
	}
	pl->size ++;
	return 1;
	}
	else{
		return 0;
	}
}

void deleteList(int pos ,listEntry *pitem , List *pl)
{
	ListNode *tmp ;
	int i ;
	if(pos == 0)
	{
		*pitem = pl->head->entry;
		pl->current = pl->head->next;
		free(pl->head);
		pl->head = tmp;
		pl->head=pl->current;
		pl->currentPos = 0;
	}
	else{
	if(pos<=pl->currentPos)
	{
		pl->currentPos = 0;
		pl->current = pl->head;
	}
	for(;pl->currentPos != pos-1  ; pl->currentPos ++)
	{
		pl->current = pl->current->next;
	}
	*pitem = pl->current->next->entry;
    tmp = pl->current->next->next;
	free(pl->current->next);
	pl->current->next = tmp;
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