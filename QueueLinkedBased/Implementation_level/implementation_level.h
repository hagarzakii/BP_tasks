typedef int queueEntry; 

typedef struct queuenode{
	queueEntry entry;
	struct queuenode *next;
}queueNode;

typedef struct queue{
	queueNode *front;
	queueNode *rear;
	int size;
}Queue;

void createQueue(Queue *pq);
int append(queueEntry item , Queue *pq);
void serve (queueEntry *item , Queue *pq);
int queueEmpty (Queue *pq);
int queueFull(Queue *pq);
int queueSize (Queue *pq);
void clearQueue(Queue *pq);
void traverseQueue(Queue *pq , void(*pf)(queueEntry));