#include <stdio.h>
#include <stdlib.h>
#include "implementation_level.h"

void createStack(Stack *ps)
{
	ps->top = NULL;
	ps->size = 0;
}

int stackFull(Stack *ps)
{
	return 0;
}

int stackEmpty(Stack *ps)
{
	return ps->top == NULL;
}

void push(stackEntry item , Stack *ps)
{
	stackNode *pn = (stackNode*) malloc(sizeof(stackNode));
	pn->entry = item;
	pn->next = ps->top;
	ps->top = pn;
	ps->size ++;
}

void pop(stackEntry *pitem , Stack *ps)
{
	*pitem = ps->top->entry;
	stackNode *pn;
	pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
	ps->size --;
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