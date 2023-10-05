#include "../global.h"
typedef struct stack {
	int top;
	stackEntry entry[MAX_STACK];
}Stack;

void createStack(Stack *ps);
int stackFull(Stack *ps);
int stackEmpty(Stack *ps);
void push(stackEntry item , Stack *ps);
void pop(stackEntry *pitem , Stack *ps);
void clearStack(Stack *ps);
void stackTop(stackEntry *pitem , Stack *ps);
int stackSize(Stack *ps);
void traverseStack(Stack *ps , void (*pf)(stackEntry item));