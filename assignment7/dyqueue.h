

#ifndef DYQUEUE_H
#define DYQUEUE_H

#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node* next;
}node;

typedef struct
{
	node* front;
	node* rear;
}queue;


void init(queue *q)
{
	q->front = NULL;
	q->rear = NULL;

}

void add(queue *q,int value)
{
	node* newNode = (node*)malloc(sizeof(node));
	if(newNode == NULL)
	{
		printf("Memory allocation falied \n");
		return;
	}

	newNode->data = value;
	if(q->rear == NULL)
	{
		q->front = newNode;
		q->rear = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = q->front;
		q->rear->next = newNode;
		q->rear = newNode;
	}
	printf("Add %d to the queu \n",value);


}


void delete(queue *q)
{
	if(q->front == NULL)
	{
		printf("Queue is empty Cannot delete \n");
		return;
	}
	node* temp = q->front;
	if(q->front == q->rear)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		q->rear->next = q->front->next;
		q->front = q->front->next;
	}
	printf("Deleted %d from the queue \n",temp->data);
	free(temp);
}


int peek(queue *q)
{
	if(q->front == NULL)
	{
		printf("Queue is empty ! No front element \n");
		return -1;

	}
	return q->front->data;
}


int isEmpty(queue *q)
{

	return (q->front == NULL);
}

int isFull(queue *q)
{
	return 0;
}

#endif
