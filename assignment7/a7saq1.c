#include "stqueue.h"

int main()
{
	queue q	;
	init(&q);

	int choice ,value;

	do
	{
		printf("Menu Queue \n");
		printf("\n1.Add \n2.Delete\n3.Peek\n4.Check if queue is empty \n5.Check if queue is full \n6.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{

			case 1:
				printf("Enter value to add in the queue : ");
				scanf("%d",&value);
				add(&q,value);
				break;
			case 2:
				delete(&q);
				break;
			case 3:
				value = peek(&q);
				if(value != -1)
				{
					printf("Front element : %d\n",value);

				}	
				break;
			case 4:
				if(isEmpty(&q))
				{
					printf("Queue is empty \n");
				}
				else
				{
					printf("Queue is not empty \n");
				}
				break;
			case 5:
				if(isFull(&q))
				{
					printf("Queue is full \n");

				}
				else
				{
					printf("Queue is not full \n");
				}
			case 6: 
				printf("Exiting....\n");
				break;
			default:
				printf("Invalid choice ! Please choose number between 1 to 6 \n");
		}

	}while(choice != 6);
	return 0;
	

}
