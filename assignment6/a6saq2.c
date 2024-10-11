#include"dystack.h"


int main()
{

	node* stack = NULL;

	int choice, value;
	while(1)
	{
		printf("\nStack Menu\n");
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Check if stack is empty \n5.Size of the stack\n5.Exit");

		printf("\nEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: 
				
				printf("Enter a value to push : ");
				scanf("%d",&value);
				push(&stack,value);
				break;
			case 2:
				if(!isEmpty(stack))
				{
					pop(&stack);

				}
				else{
					printf("Stack is empty so cannot pop out the element ");
				}
				break;
			case 3:
				if(!isEmpty(stack))
				{
					printf("Top element is : %d\n",peek(stack));

				}
				else
				{
					printf("Stack is empty , so there is not top element ");

				}	
				break;

			case 4:
				if(!isEmpty(stack))
				{
					printf("Stack is not empty \n");

				}
				else
				{
					printf("Stack is empty ");
				}
				break;
			case 5:
				printf("Current stack size is  %d \n",getSize(stack));
				break;
			case 6:
				printf("Exiting the program \n");
				return 0;
			default:
				printf("Invalid choice ! Please enter a choice between 1 to 6 \n");
				break;
		}
	}
	return 0;
}
