#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct elementtype{
	int year;
	int age;
	int tmp;
}elementType;

/*
typedef struct elementtype{
	short int etype;
	Type0 data;
	Type1 voice;
	Type2 fax;
}elementType;

#define 0 DATA
#define 1 VOICE
#define 2 FAX
void main()
{
	elementType e;
	pop(&e , &s);
	switch(e.type){
		case DATA:
		case VOICE:
		......
	}
}
not a smart way

typedef struct elementtype{
	short int etype;
	union{
	Type0 data;
	Type1 voice;
	Type2 fax;
	}info;
}elementType;

#define 0 DATA
#define 1 VOICE
#define 2 FAX
void main()
{
	elementType e;
	pop(&e , &s);
	switch(e.type){
		case DATA: e.info.data
		case VOICE: e.info.voice
		......
	}
}

*/

#define MAXELEMENTS 100

typedef elementType queueEntry;
#define MAXQUEUE MAXELEMENTS

typedef elementType stackEntry;
#define MAXSTACK MAXELEMENTS

#endif

//assume we have program that has 3 modules stack , queue and main program we created a separate header file that has common element types
