#include <stdio.h>
#include"../Implementation_level/implementation_level.h"

void display(listEntry item)
{
	printf("%d\n", item);
}

void main()
{
	listEntry item;
	List l;
	int task , size , p;
	int loop = 1 ;
	createList(&l);
	while(loop)
	{
	printf("Enter task \n"
	"1-Insert element to queue \n"
	"2-Delete queue item \n"
	"3-Display queue \n"
	"4-Find an item  with its position \n"
	"5-Size of queue \n"
	"6-Clear queue \n"
	"7-Replace an element \n");
	scanf("%d",& task);
	switch(task){
		case 1 :
		printf("Enter item\n");
	    scanf("%d" ,& item);
			if(!listFull(&l))
				{
					insertList(item ,&l);
				}
			else
            {
				printf("List is full!!\n");
			}				
	    break;
		case 2 :
			if(!listEmpty(&l))
				{
					deleteList(&item , &l);
				}
			else
            {
				printf("List is empty!!\n");
			}
		break;
        case 3 :		
			traverseList(&l , &display);
		break;
        case 4 :
        printf("Enter position of the item\n");
	    scanf("%d" ,& p);		
			retrieveList(p ,&item , &l);
			printf("Element is %d\n" , item);
		break;
        case 5:		
			size = listSize(&l);
			printf("size of queue is %d\n",size);
		break;
        case 6:		
			destroyList(&l);
		break;
		case 7:
        printf("Enter new item\n");
	    scanf("%d" ,& item);
		printf("Enter position\n");
	    scanf("%d" ,& p);		
			replaceList(p ,item , &l);
		break;
		default:
			loop = 0;
			break;
	}
	}
}

