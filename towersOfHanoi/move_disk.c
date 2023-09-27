#include <stdio.h>

//only one disk is removed at a time
//no disk should be placed on top of a smaller disk

//to move the largest disk from 1 to 3 we have to move all others from 1 to 2
//move largest from 1 to 3
//move all others from 2 to 3

//pre:there are atleast count disks on the tower start
//the top disk on each of towers temp and finish is larger than any of the top count disks on tower start
//post:the top count disks on start have been moved to finish
//temp has been returned to its starting position

//convince yourself that moveDisks really writes down the steps of moving count from start to finish using temp

//steps: 2^power count - 1

void moveDisks(int count , int start , int finish , int temp)
{
	//int swap
	//while(count>0)
	if(count > 0)
	{
		moveDisks(count - 1 , start , temp , finish);
		printf("Move disk %d from %d to %d \n" , count , start ,finish);
		moveDisks(count - 1 , temp , finish , start);
		//count --;
		//swap = start;
		//start = temp;
		//temp = swap;
	}
}

void main()
{
	int count = 3;
	int start = 1;
	int finish = 3;
	int temp = 2;
	moveDisks(count , start , finish , temp);
}