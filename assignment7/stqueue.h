#ifndef STQUEUE_H
#define STQUEUE_H

#include<stdio.h>
#include<stdlib.h>

#define MAX 5


typedef struct {
	int items[MAX];
	int front , rear;

}queue;


void init(queue *q)
{
	q->front = -1;
	q->rear = -1;


}

int isEmpty(queue *q)
{
	if(q->front == -1)
	{
		return 1;
	}
	return 0;
}



void add(queue* q, int x)
{
	if(q->rear == MAX -1)
	{
		printf("Queue is full cannot add");
		return;
	}
	if(q->front == -1)
	{
		q->front = 0;
	}

	q->rear++;
	q->items[q->rear] = x;
	printf("Add %d to the queue \n");

}

void delete(queue *q)
{
	if(q->front == -1)
	{

		printf("Queue is empty cannot delete \n");
		return;
	}

	printf("Delete %d from the queue \n",q->items[q->front]);
	q->front++;
	if(q->front > q->rear)
	{

		q->front = -1;
		q->rear = -1;
	}
}

int peek(queue *q)
{
	if(q->front == -1)
	{
		printf("Queue is empty No front element \n");
		return -1;
	}
	return q->items[q->front];
}


int isFull(queue *q)
{

	if(q->rear == MAX -1)
	{
		return 1;
	}

	return 0;
}


#endif


