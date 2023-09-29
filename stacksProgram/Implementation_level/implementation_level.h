typedef char stackEntry; 

typedef struct stacknode{
	stackEntry entry;
	struct stacknode *next;
}stackNode;

typedef struct stack {
	stackNode *top;
	int size;
	int minimum;
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
void firstStackElement (stackEntry *pitem , Stack *ps);
int parenthesis (char s[] , int size , Stack *pstr , stackEntry *pitem);
int findMin (Stack *ps);
void stackCopy(Stack *ps1 , Stack *ps3 , Stack *ps2);