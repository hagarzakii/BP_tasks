#include <stdio.h>
#include "implementation_level.h"

void createList(List *pl)
{
	pl->size = 0;
}

int listFull(List *pl)
{
	return pl->size==MAX_LIST;
}

int listEmpty(List *pl)
{
	return !pl->size;
}

void insertList(int p ,listEntry item , List *pl)
{
	for(int i = pl->size-1 ; i >= p ; i--)
	{
		pl->entry[i+1] = pl->entry[i];
	}
	pl->entry[p] = item;
	pl->size ++;
}

void deleteList(int p ,listEntry *pitem , List *pl)
{
	*pitem = pl->entry[p];
	for(int i = p+1 ; i <= pl->size-1 ; i++)
	{
		pl->entry[i-1] = pl->entry[i];
	}		
	pl->size --;
}

void destroyList(List *pl)
{
	pl->size = 0;
}

void retrieveList(int p ,listEntry *pitem , List *pl)
{
	*pitem = pl->entry[p];
}

int listSize(List *pl)
{
	return pl->size ;
}

void replaceList(int p ,listEntry item , List *pl)
{
	pl->entry[p] = item;
}

void traverseList(List*pl , void (*pf)(listEntry item))
{
	for (int i = 0 ; i<pl->size ; i++)
	{
		(*pf)(pl->entry[i]);
	}
}