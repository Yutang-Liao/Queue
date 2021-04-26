#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int isEmpty();
int isFull();
void dequeue();
void enqueue(int newitem);
void startQueue();
int rear = -1 ;
int front =  -1;
void display();
int arr[MAX] ;

int main()
{
	dequeue(); //this operation is fail
	
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	
	enqueue(6);//this operation is fail
	dequeue();
	
	display();
	return 0;
}

void enqueue(int newitem)
{
	if(isFull())
		printf("the queue is full!\n");
	else
	{
		if(front == (-1) ) front = 0; //初始化front  
		rear = (rear +1) % MAX; //這樣rear 指針才有circular 的效果  
		arr[rear] = newitem;
		printf("You inserted -> %d\n",newitem); 
	}
} 
void dequeue()
{
	int element ;
	if(isEmpty())
		{
		printf("the queue is empty!\n");
		return;
		}
	else
	{
		element = arr[front];
		if(front == rear) //reset if front index and rear index is the same 
			{
				front =-1;
				rear = -1;
			}
		else
		{
			front = (front +1) % MAX ;//update front
		}
		printf("You dequeue => %d",element);
	}
	return;
} 
int isFull()
{
	if( (front == rear +1 ) || (front == 0 && rear == MAX -1 )) //有兩種情況，分別為尾端+1 = 頭 和 當頭=0 且 尾 = MAX -1 ) 
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if(front == -1 )
		return 1;
	else
		return 0;
}
// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front index-> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % MAX) {
      printf("%d ", arr[i]);
    }
    printf("%d ", arr[i]);//front = rear 時 
    printf("\n Rear index-> %d \n", rear);
  }
}
