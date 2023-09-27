//#define STACK_ENTRY_CHAR

#define STACK_ENTRY_DOUBLE

#ifdef STACK_ENTRY_CHAR
typedef char stackEntry;
#else
typedef double stackEntry;
#endif

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
void push(stackEntry item , Stack *ps);
void pop(stackEntry *pitem , Stack *ps);
void clearStack(Stack *ps);
void stackTop(stackEntry *pitem , Stack *ps);
int stackSize(Stack *ps);
void traverseStack(Stack *ps , void (*pf)(stackEntry item));