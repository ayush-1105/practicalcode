#ifndef DYSTACK_H
#define DYSTACK_H


#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node* next;

}node;

node *createNode(int value)
{
	node* newNode = (node*)malloc(sizeof(node));

	if(!newNode)
	{
		printf("Memory allocation falied ");
		exit(1);
	}
	
	newNode->data = value;
	newNode->next = NULL;
	return newNode;

}
	

void push(node** top, int value)
{
	node* newNode = createNode(value);
	newNode->next = *top;
	*top = newNode;
	printf("Pushed %d onto the stack : ",value);


}

int pop(node** top)
{
	if(*top == NULL)
	{
		printf("Stack underflow so cannot able to pop out ");
		exit(1);
	}
	node* temp = *top;
	*top = (*top)->next;

	int poppedValue = temp->data;
	free(temp);

	printf("Popped %d from the stack \n",poppedValue);
	return poppedValue;
}

int peek(node* top)
{
	if(top == NULL)
	{
		printf("Stack is empty! So there is no top element ");
		exit(1);
	}
	return top->data;
}

int isEmpty(node* top)
{
	return top == NULL;
}


int getSize(node* top)
{
	int size = 0;
	node* temp = top;
	while(temp != NULL)
	{
		size++;
		temp = temp->next;	
	}
	return size;

}


#endif


