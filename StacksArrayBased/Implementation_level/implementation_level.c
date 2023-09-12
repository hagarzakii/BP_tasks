#include <stdio.h>
#include "implementation_level.h"

void createStack(Stack *ps)
{
	ps->top = 0;
}

int stackFull(Stack *ps)
{
	if(ps->top == MAX_STACK)
	{
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}

int stackEmpty(Stack *ps)
{
	if(ps->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(stackEntry item , Stack *ps)
{
	ps->entry[ps->top]=item;
	ps->top ++ ;
}

void pop(stackEntry *pitem , Stack *ps)
{
	ps->top --;
	*pitem = ps->entry[ps->top];
}

void clearStack(Stack *ps)
{
	ps->top = 0;
}

void stackTop(stackEntry *pitem , Stack *ps)
{
	*pitem = ps->entry[ps->top -1];
}

int stackSize(stackEntry *pitem , Stack *ps)
{
	return ps->top ;
}

void traverseStack(Stack *ps , void (*pf)(stackEntry item))
{
	for (int i = ps->top ; i>0 ; i--)
	{
		(*pf)(ps->entry[i-1]);
	}
}