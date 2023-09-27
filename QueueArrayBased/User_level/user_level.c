#include <stdio.h>
#include"../Implementation_level/implementation_level.h"

void display(queueEntry item)
{
	printf("%d\n", item);
}

void main()
{
	queueEntry item;
	Queue q;
	createQueue(&q);
	int task , size;
	int loop = 1 ;
	while(loop)
	{
	printf("Enter task \n"
	"1-append \n"
	"2-serve \n"
	"3-display queue \n"
	"4-size of queue \n"
	"5-clear queue \n");
	scanf("%d",& task);
	switch(task){
		case 1 :
		printf("Enter queue item\n");
	    scanf("%d" ,& item);
			if(!queueFull(&q))
				{
					append(item , &q);
				}
			else
            {
				printf("queue is full!!\n");
			}				
	    break;
		case 2 :
			if(!queueEmpty(&q))
				{
					serve(&item , &q);
				}
			else
            {
				printf("queue is empty!!\n");
			}
		break;
        case 3 :		
			traverseQueue(&q , &display);
		break;
        case 4:		
			size = queueSize(&q);
			printf("size of queue is %d\n",size);
		break;
        case 5:		
			clearQueue(&q);
		break;
		default:
			loop = 0;
			break;
	}
	}
}

