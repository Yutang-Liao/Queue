#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int isEmpty();
int isFull();
void dequeue();
void enqueue(int newitem);
void startQueue();
int rear ,front ,count;
int arr[MAX] = {0};

int main()
{
	startQueue();
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(6);
	dequeue();
	int i ;
	for(i=front;i<=rear;i++)
		{
		printf("queue in array :%d\n",arr[i]);
		}
	return 0;
}
void startQueue()
{
	rear = -1;
	front = -1;
	count = 0;
	return;
}
void enqueue(int newitem)
{
	if(isFull())
		{
		printf("the queue is full!\n");
		return;
		}
	else if( front == (-1))
	{
		front = 0;
	}
	rear++;
	arr[rear] = newitem;
	count++;
	return;
} 
void dequeue()
{
	if(isEmpty())
		{
		printf("the queue is empty!\n");
		return ;
		}
	if(rear== (MAX-1) )
	{
		rear =-1;
		front = -1;
		return ;
	}
	count--;
	printf("dequeue: %d \n",arr[front]);
	front++;
	return;
} 
int isFull()
{
	if(rear == (MAX-1) )
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if(count == 0 )
		return 1;
	else
		return 0;
}

