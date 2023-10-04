#define MAX_LIST 100
typedef int listEntry; 

typedef struct list {
	int size;
	listEntry entry[MAX_LIST];
}List;

void createList(List *pl);
int listFull(List *pl);
int listEmpty(List *pl);
int listSize(List *pl);
void destroyList(List *pl);
void insertList(int p ,listEntry item , List *pl);
void deleteList(int p ,listEntry *pitem , List *pl);
void retrieveList(int p ,listEntry *pitem , List *pl);
void replaceList(int p ,listEntry item , List *pl);
void traverseList(List*ps , void (*pf)(listEntry item));