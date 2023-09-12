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
	int task , size;
	int loop = 1 ;
	createStack(&s);
	while(loop)
	{
	printf("Enter task \n"
	"1-push \n"
	"2-pop \n"
	"3-display stack \n"
	"4-top of stack \n"
	"5-size of stack \n"
	"6-clear stack \n");
	scanf("%d",& task);
	switch(task){
		case 1 :
		printf("Enter stack item\n");
	    scanf("%d" ,& item);
			if(!stackFull(&s))
				{
					push(item , &s);
				}
			else
            {
				printf("stack is full!!\n");
			}				
	    break;
		case 2 :
			if(!stackEmpty(&s))
				{
					pop(&item , &s);
				}
			else
            {
				printf("stack is empty!!\n");
			}
		break;
        case 3 :		
			traverseStack(&s , &display);
		break;
        case 4 :		
			stackTop(&item , &s);
			printf("top of stack is %d\n" , item);
		break;
        case 5:		
			size = stackSize(&item , &s);
			printf("size of stack is %d\n",size);
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

