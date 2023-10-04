typedef int listEntry; 

typedef struct listNode {
	listEntry entry;
	struct listNode *next;
}ListNode;

typedef struct list{
	ListNode *head;
	int size;
}List;

void createList(List *pl);
int listFull(List *pl);
int listEmpty(List *pl);
int listSize(List *pl);
void destroyList(List *pl);
int insertList(int p ,listEntry item , List *pl);
void deleteList(int p ,listEntry *pitem , List *pl);
void retrieveList(int p ,listEntry *pitem , List *pl);
void replaceList(int p ,listEntry item , List *pl);
void traverseList(List*ps , void (*pf)(listEntry item));