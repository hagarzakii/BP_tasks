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
	"1-Insert element to list \n"
	"2-Delete list item \n"
	"3-Display list \n"
	"4-Find an item  with its position \n"
	"5-Size of list \n"
	"6-Clear list \n"
	"7-Replace an element of list \n");
	scanf("%d",& task);
	switch(task){
		case 1 :
		printf("Enter item\n");
	    scanf("%d" ,& item);
		printf("Enter position\n");
	    scanf("%d" ,& p);
			if(!listFull(&l))
				{
					insertList(p,item ,&l);
				}
			else
            {
				printf("List is full!!\n");
			}				
	    break;
		case 2 :
		printf("Enter position of the item\n");
	    scanf("%d" ,& p);
			if(!listEmpty(&l))
				{
					deleteList(p ,&item , &l);
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
			printf("size of list is %d\n",size);
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

