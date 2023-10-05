#include <stdio.h>
#include"../Implementation_level/implementation_level.h"

void display(stackEntry item)
{
	printf("%d\n", item);
}

void main()
{
	stackEntry item;
	Stack s;
	Stack tmp;
	createStack(&tmp);
	int task , size;
	int loop = 1 ;
	createStack(&s);
	while(loop)
	{
	printf("Enter task \n"
	"1-Append \n"
	"2-Serve \n"
	"3-Display queue \n"
	"4-Top of queue \n"
	"5-Size of queue \n"
	"6-Clear queue \n"
	"7-Exit\n");
	scanf("%d",& task);
	switch(task){
		case 1 :
		printf("Enter item\n");
	    scanf("%d" ,& item);
			if(!stackFull(&s))
				{
					if(!push(item , &s))
					{
						printf("error");
					}
				}
			else
            {
				printf("queue is full!!\n");
			}				
	    break;
		case 2 :
			if(!stackEmpty(&s))
				{
					while(stackSize(&s) > 1)
					{
					pop(&item , &s);
					push(item , &tmp);
					}
					pop(&item , &s);
					while(stackSize(&tmp) != 0)
					{
					pop(&item , &tmp);
					push(item , &s);
					}
				}
			else
            {
				printf("queue is empty!!\n");
			}
		break;
        case 3 :		
			traverseStack(&s , &display);
		break;
        case 4 :		
			stackTop(&item , &s);
			printf("top of queue is %d\n" , item);
		break;
        case 5:		
			size = stackSize(&s);
			printf("size of queue is %d\n",size);
		break;
        case 6:		
			clearStack(&s);
		break;
		default:
			loop = 0;
			break;
	}
	}
}

