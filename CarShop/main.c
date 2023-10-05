#include <stdio.h>
#include"Stacks/stacks.h"
#include"Queues/queues.h"
#include"global.h"

void display(queueEntry item)
{
	printf("*******************\n");
	printf("customer name : %s\n", item.name);
	printf("customer id : %d\n", item.id);
	printf("customer car model year %d\n", item.modelYear);
	printf("*******************\n");
}

int main()
{
	Queue customers;
	Stack custom;
	Stack tmp;
	createStack(&custom);
	createStack(&tmp);
	createQueue(&customers);
	elementType newCustomer;
	int task ;
	int loop = 1 ;
	while(loop)
	{
	printf("***********************************\n"
	"Enter choice :\n"
	"1-Add a new customer \n"
	"2-Serve a customer \n"
	"3-How many customers are waiting? \n"
	"4-Display customers information \n"
	"5-Display customers information in a most-recent order \n"
	"6-Exit \n"
	"***********************************\n");
	scanf("%d",& task);
	switch(task){
		case 1 :    
		if(!queueFull(&customers))
		{
			printf("Enter customer name :\n");
			scanf("%s" , newCustomer.name);
			printf("Enter customer id :\n");
			scanf("%d" , &newCustomer.id);
			printf("Enter car model year :\n");
			scanf("%d" , &newCustomer.modelYear);
			append(newCustomer , &customers);
			push(newCustomer , &custom);
		}
		else
		{
			printf("Can't add more customers\n");
		}
		break;
		case 2 :
		if(!queueEmpty(&customers))
		{
			elementType servedCustomer;
            serve(&servedCustomer, &customers);
            display(servedCustomer);
			while(stackSize(&custom) > 1)
				{
					pop(&servedCustomer , &custom);
					push(servedCustomer , &tmp);
				}
					pop(&servedCustomer , &custom);
					while(stackSize(&tmp) != 0)
				{
					pop(&servedCustomer , &tmp);
					push(servedCustomer , &custom);
				}
		}
		else
		{
			printf("No customers in queue\n");
		}
		break;
        case 3 :
            printf("There are %d customers waiting\n" , queueSize(&customers));	
		break;
        case 4 :
		    traverseQueue(&customers , &display);
		break;
        case 5:	
            traverseStack(&custom , &display);
		break;
		default:
			loop = 0;
			break;
	}
	}
	return 0;
}