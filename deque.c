#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void addFront(int * ,int ,int * ,int *);
void addRear(int * ,int  ,int * ,int *);
int delFront(int * , int * ,int *);
int delRear(int * , int * ,int *);
void display(int *);
int count(int *);

int main()
{
	int arr[MAX]; 
	int front , rear ,item_delete ,n ,i;
	for(i=0 ; i < MAX; i++)
		arr[i] = 0;
		
	front = rear = -1;
	
	addRear(arr , 5,  &front , &rear);
	addFront(arr , 12 ,&front , &rear);
	addRear(arr , 11,  &front , &rear);
	addFront(arr , 5 ,&front , &rear);
	addRear(arr , 6,  &front , &rear);
	addFront(arr , 8 ,&front , &rear);
	printf("Elements at deque:\n");
	display(arr);
	item_delete = delFront(arr , &front , &rear );
	
	printf("remove item : %d\n",item_delete);
	printf("After delete ,Elements at deque:\n");
	display(arr);
	
	addRear(arr , 16,  &front , &rear);
	addRear(arr , 7 ,&front , &rear);
	
	printf("After addition  ,Elements at deque:\n");
	display(arr);
	
	item_delete = delRear(arr , &front , &rear );
	printf("After delete ,Elements at deque:\n");
	display(arr);
	
	n = count(arr);
  	printf("Total number of elements in deque: %d\n", n);
		
}

void addFront(int *a, int item ,int *pFront ,int *pRear)
{
	int c , shift_index ,i ;
	if(*pFront == 0 && *pRear == (MAX-1) )
	{
		printf("the deque is full!\n");
		return;
	}
	if(*pFront == -1)
	{
		*pFront = *pRear = 0;
		a[*pFront] = item;
		return;
	}
	if(*pRear != (MAX -1)) // 我們以pRear 作為是否元素已填滿 , 因為這是circular queue  
	{
		c = count(a);
		shift_index = *pRear +1 ;//addFront 的時候 ,shift index = pRear +1 
		for(i=1 ; i <= c ; i++) // 總共shift 的次數 
		{
			a[shift_index]  = a[shift_index -1];
			shift_index -- ;
		} 
		a[shift_index] = item ;
		*pFront = shift_index ;
		(*pRear)++;
	}
	else
	{
		(*pFront)--;
		a[*pFront] = item;
	}
}
void addRear(int *a, int item ,int *pFront ,int *pRear)
{
	int i ,shift_index;
	if(*pFront == 0 && *pRear == (MAX-1) )
	{
		printf("the deque is full!\n");
		return;
	}
	if(*pFront == -1)
	{
		*pFront = *pRear = 0;
		a[*pRear] = item;
		return;
	}
	
	if(*pRear == (MAX -1)) // 若prear在後面 ,我們向前移動它   
	{
		shift_index = *pFront -1 ; //addRear 的時候 ,shift index = pfront -1 
		for (i = *pFront - 1; i < *pRear; i++) {
     		 shift_index = i;
      		if (shift_index == MAX - 1) //????? 到最後要往前挪的元素為尾端的時候，直接設0 
        	a[shift_index] = 0;
      		else
       		a[shift_index] = a[i + 1];
    }
	(*pRear)--;
    (*pFront)--;
	}
	//後面沒滿的情況直接用下面 
	(*pRear)++;
	a[*pRear] = item ;
	return ;
}
int delFront(int *a , int *pFront ,int *pRear)
{
	int item ;
	if(*pFront == -1)
	{
		printf("the deque is empty!\n");
		return 0;
	}
	item = a[*pFront];
	a[*pFront] = 0;
	if(*pFront == *pRear)
		(*pFront) = (*pRear) = -1;
	else
	(*pFront)++;
	
	return item;
}
int delRear(int *a , int *pFront ,int *pRear)
{
	int item ;
	if(*pFront == -1)
	{
		printf("the deque is empty!\n");
		return 0;
	}
	
	item = a[*pRear];
	a[*pRear] = 0;
	if(*pFront == *pRear)
		(*pFront) = (*pRear) = -1;
	else
	(*pRear)--;
	
	return item;
}
int count(int *a)
{
	int i;
	int c = 0;
	for(i=0 ; i<MAX ; i++)
	{
		if(a[i] != 0)
			c++ ;
	}
	return c;
}
void display(int *arr) {
  int i;

  printf("front: ");
  for (i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
    printf(" = rear \n");
}
