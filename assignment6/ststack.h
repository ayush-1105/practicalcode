#ifndef STSTACK_H
#define STSTACT_H


#include<stdio.h>
#include<stdlib.h>


#define MAX 100

typedef struct
{
	int data[MAX];
	int top;

}stack;


void init(stack *s)

{
	s->top = -1;
}

void push(stack *s, int value)
{
	if(s->top == MAX - 1)
	{
		printf("Stack over cannot push the value %d",value);
		return;
	}

	s->data[++s->top] = value;
	printf("Pushed %d onto the stack ",value);
}


int pop(stack *s)
{
	if(s->top == -1)
	{
		printf("Stack has no value . Stack underflow ! Cannot pop out the data ");
		exit(1);
	}

	printf("Popped %d from the stack ",s->data[s->top]);
	return s->data[s->top--];
}


int peek(stack *s)
{
	if(s->top == -1)
	{
		printf("Stack is empty !No top element is availabe to display : ");
		exit(1);
	}

	return s->data[s->top];
}


int isEmpty(stack *s)
{
	return s->top == -1;
}


int getSize(stack *s)
{

	return s->top + 1;
}


#endif






