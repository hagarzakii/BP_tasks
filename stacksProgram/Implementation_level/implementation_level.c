#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "implementation_level.h"

void createStack(Stack *ps)
{
	ps->top = NULL;
	ps->size = 0;
	ps->minimum = INT_MAX;
}

int stackFull(Stack *ps)
{
	return 0;
}

int stackEmpty(Stack *ps)
{
	return ps->top == NULL;
}

int push(stackEntry item , Stack *ps)
{
	stackNode *pn = (stackNode*) malloc(sizeof(stackNode));
	if(!pn)
	{
		return 0;
	}else{
	pn->entry = item;
	pn->next = ps->top;
	ps->top = pn;
	ps->size ++;
	if (ps-> size == 1)
	{
		ps->minimum = item;
	}
	else if(ps->minimum > item){
		ps-> minimum = item ;
	}
	return 1;
	}
}

void pop(stackEntry *pitem , Stack *ps)
{
	*pitem = ps->top->entry;
	stackNode *pn;
	pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
	ps->size --;
	
	if(ps->minimum == *pitem){
	ps->minimum = INT_MAX;
	stackNode *pfind = ps->top;
	while(pfind != NULL)
	{
		if(pfind->entry < ps->minimum)
		{
			ps->minimum = pfind ->entry;
		}
		pfind = pfind->next;
	}
	}
}

void clearStack(Stack *ps)
{
	stackNode *pn = ps->top;
	while(pn != NULL)
	{
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
	
}

void stackTop(stackEntry *pitem , Stack *ps)
{
	*pitem = ps->top->entry;
}

int stackSize(Stack *ps)
{
	return ps->size ;
}

void traverseStack(Stack *ps , void (*pf)(stackEntry item))
{
	stackNode *pn = ps->top;
	while(pn != NULL)
	{
		(*pf)(pn->entry);
		pn = pn->next;
	}
}

void firstStackElement (stackEntry *pitem , Stack *ps)
{
	stackNode *pn = ps->top;
	while(pn->next != NULL)
	{
		pn = pn->next;
	}
	*pitem = pn->entry; 
}

int parenthesis (char st[] , int size , Stack *pstr , stackEntry *pitem)
{
	for(int i = 0 ; i < size ; i++)
	{
		if(st[i] == '(' || st[i] == '{' || st[i] == '[')
			{
				push(st[i] , pstr);
			}
		else if(st[i] == ')' || st[i] == '}' || st[i] == ']')
		{
			if(!stackEmpty(pstr))
			{
				pop(pitem , pstr);
				if (st[i] - *pitem > 2)
				{
					return 0;
				}
			}
			else{
				return 0;
			}
		}
	}
	if(!stackEmpty(pstr))
	{
		return 0;
	}
	return 1 ;
}

int findMin (Stack *ps)
{
	return ps->minimum;
}

void stackCopy(Stack *ps1 , Stack *ps3 , Stack *ps2)
{
	//copy stack p1 to p3 using p2
	stackNode *pn = ps1->top;
	while(pn != NULL)
	{
		push(pn->entry , ps2);
		pn=pn->next;
	}
	pn=ps2->top;
	while(pn != NULL)
	{
		push(pn->entry , ps3);
		pn=pn->next;
	}
	clearStack(ps2);
}