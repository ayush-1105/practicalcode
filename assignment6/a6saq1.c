#include"ststack.h"



int main()

{
	stack stack;
	init(&stack);

	int choice , value;

	while(1)
	{

		printf("\nStack Menu ");
		printf("\n1.Push\n2.Pop\n3.Peek\n4.check is stack is empty \n5.Stack size\n6.exit ");
		printf("Enter your choice ");
		scanf("%d",&choice);

		switch(choice)
		{

			case 1:
				printf("Enter a value to push : ");
				scanf("%d",&value);
				push(&stack,value);
				break;
			case 2:
				if(!isEmpty(&stack))
				{
					pop(&stack);
				}
				else
				{
					printf("Stack is empty ,cannot pop ");

				}
				break;

			case 3:
				if(!isEmpty(&stack))
				{
					printf("Top element is %d\n",peek(&stack));
					
				}
				else
				{
					printf("Stack is empty , not top element here ");

				}
				break;

			case 4:
				if(isEmpty(&stack))
				{
					printf("Stack is empty ");

				}
				else{
					printf("Stack is not empty ");
				}
				break;
			case 5:
				printf("Current stack size is : %d \n",getSize(&stack));
				break;
			case 6:
				printf("Exiting the program \n");
				return 0;
			default:
				printf("Invalid choice ! Please enter a number between 1 to 6 \n");
				break;
		}

	}

	return 0;
}
