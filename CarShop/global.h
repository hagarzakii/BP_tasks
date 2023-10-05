#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct elementType{
	char name [50];
	int id;
	int modelYear;
}elementType;

#define MAXELEMENTS 100

typedef elementType queueEntry;
#define MAX_QUEUE MAXELEMENTS

typedef elementType stackEntry;
#define MAX_STACK MAXELEMENTS

#endif
