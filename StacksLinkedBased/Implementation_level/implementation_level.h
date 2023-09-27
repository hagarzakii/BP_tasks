typedef int stackEntry; 

typedef struct stacknode{
	stackEntry entry;
	struct stacknode *next;
}stackNode;

typedef struct stack {
	stackNode *top;
	int size;
}Stack;

void createStack(Stack *ps);
int stackFull(Stack *ps);
int stackEmpty(Stack *ps);
int push(stackEntry item , Stack *ps);
void pop(stackEntry *pitem , Stack *ps);
void clearStack(Stack *ps);
void stackTop(stackEntry *pitem , Stack *ps);
int stackSize(Stack *ps);
void traverseStack(Stack *ps , void (*pf)(stackEntry item));