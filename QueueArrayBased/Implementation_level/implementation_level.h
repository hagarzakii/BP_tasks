#define MAX_QUEUE 100

typedef int queueEntry; 

typedef struct queue{
	int front;
	int rear;
	int size;
	queueEntry entry [MAX_QUEUE];
}Queue;

void createQueue(Queue *pq);
void append(queueEntry item , Queue *pq);
void serve (queueEntry *item , Queue *pq);
int queueEmpty (Queue *pq);
int queueFull(Queue *pq);
int queueSize (Queue *pq);
void clearQueue(Queue *pq);
void traverseQueue(Queue *pq , void(*pf)(queueEntry));