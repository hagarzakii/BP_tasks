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
	Queue tmp;
	createQueue(&tmp);
	createQueue(&q);
	int task , size;
	int loop = 1 ;
	while(loop)
	{
	printf("Enter task \n"
	"1-push \n"
	"2-pop \n"
	"3-display stack \n"
	"4-size of stack \n"
	"5-clear stack \n"
	"6-Exit \n"
	);
	scanf("%d",& task);
	switch(task){
		case 1 :
		printf("Enter item\n");
	    scanf("%d" ,& item);
			if(!queueFull(&q))
				{
					if(!append(item , &q)){
						printf("error");
					}
				}
			else
            {
				printf("stack is full!!\n");
			}				
	    break;
		case 2 :
			if(!queueEmpty(&q))
				{
					while(queueSize(&q) > 1)
					{
						serve(&item , &q);
						append(item , &tmp);
					}
					serve(&item , &q);
					while(queueSize(&tmp) != 0)
					{
						serve(&item , &tmp);
						append(item , &q);
					}
				}
			else
            {
				printf("stack is empty!!\n");
			}
		break;
        case 3 :		
			traverseQueue(&q , &display);
		break;
        case 4:		
			size = queueSize(&q);
			printf("size of stack is %d\n",size);
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

