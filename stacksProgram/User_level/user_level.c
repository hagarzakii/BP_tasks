#include <stdio.h>
#include <string.h>
#include"../Implementation_level/implementation_level.h"

void display(stackEntry item)
{
	printf("%d\n", item);
}

void main()
{
	stackEntry item;
	Stack s;
	Stack s2;
	Stack s3;
	Stack str;
	createStack(&s);
	createStack(&s2);
	createStack(&s3);
	createStack(&str);
	char st[100];
	int task , size , mini;
	int loop = 1 ;
	while(loop)
	{
	printf("**************************\n"
	"Enter task \n"
	"1-push \n"
	"2-pop \n"
	"3-display stack \n"
	"4-top of stack \n"
	"5-size of stack \n"
	"6-clear stack \n"
	"7-First stack element\n"
	"8- Find min element in the stack\n"
	"9-Parenthesis pairing in a string\n"
	"10-Copy stack to another one\n"
	"11-Exit\n"
	"**************************\n");
	scanf("%d",& task);
	printf("\n");
	switch(task){
		case 1 :
		printf("Enter stack item\n");
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
			size = stackSize(&s);
			printf("size of stack is %d\n",size);
		break;
        case 6:		
			clearStack(&s);
		break;
		case 7:
		firstStackElement (&item ,&s);
		printf("first element of stack is %d\n" , item);
		break;
		case 8:
		mini = findMin (&s) ;
		printf("The min element is %d\n" , mini);
		break;
		case 9:
		scanf("%s" , st);
		int size = strlen(st);
		if(parenthesis (st,size,&str,&item))
		{
			printf("Parenthesis are paired\n");
		}
		else{
			printf("Parenthesis are not paired\n");
		}
		break;
		case 10:
		stackCopy(&s ,&s3 ,&s2);
		traverseStack(&s3 , &display);
		break;
		default:
			loop = 0;
			break;
	}
	}
}

