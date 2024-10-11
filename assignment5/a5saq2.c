#include<stdio.h>

#include<stdlib.h>


struct node
{
	int data;
	struct node* prev;
	struct node* next;
};

struct node* createNode(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}



struct node* create(struct node* head)
{
	int n, data;
	printf("Enter the number of nodes ");
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		printf("Enter the data for the node %d ",i  + 1);
		scanf("%d",&data);
		struct node* newNode = createNode(data);
		if(head == NULL)
		{
			head = newNode;
		}

		else
		{
			struct node* temp = head;
			while(temp->next != NULL)
			{
				temp = temp->next;

			}
			temp->next = newNode;
			newNode->prev = temp;
		}
	}

	return head;


}


struct node* insertAtStart(struct node* head, int data)

{

	struct node* newNode = createNode(data);
	newNode->next = head;
	if(head != NULL)

	{
		head->prev = newNode;
}
	head = newNode;
	return head;
}
struct node* insertAtEnd(struct node* head, int data)
{
	struct node* newNode = createNode(data);
	if( head == NULL)
	{
		return newNode;

	}

	struct node* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;
	return head;
}




struct node* insertAtPostion(struct node* head,int data, int position)
{
	if(position == 1)
	{
		return insertAtStart(head, data);
	}

	struct node* newNode = createNode(data);
	struct node* temp = head;


	for( int i = 1; i < position -1 && temp != NULL; i++)

	{

		temp = temp->next;
	}

	if(temp == NULL)
	{
		printf("Invalid position to enter the data in the node ");
		free(newNode);
	}

	else
	{
		newNode->next = temp->next;
		if(temp->next != NULL)
		{
			temp->next->prev = newNode;
		}
		temp->next = newNode;
		newNode->prev = temp;


	}	
	return head;
}


struct node* insert(struct node* head)
{
	int data, choice, position;
	printf("Enter the data to insert in the node : ");
	scanf("%d",&data);

	printf("Where do you want to insert the data in the node: ");
	printf("1.At the start \n2.At the end.\n3.At a specifice positon ");

	printf("\nEnter your choice ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			head = insertAtStart(head, data);
			break;
		case 2:
			head = insertAtEnd(head, data);
			break;
		case 3:
			printf("Enter the postion where to want to insert the data : ");
			scanf("%d",&position);
			head = insertAtPostion(head, data, position);
			break;
		default:
			printf("Invalid choice ! \n");
	}

	return head;
}

struct node* delete(struct node* head, int position)
{
	if(head == NULL)
	{
		printf("List is empty \n");
		return head;
	}	

	struct node* temp = head;
	if(position == 1)
	{
		head = head->next;
		if(head != NULL)
		{
			head->prev = NULL;
		}

		free(temp);
		return head;
	}

	for(int i = 1; i < position && temp != NULL; i++)
	{

		temp = temp->next;

	}
	if(temp == NULL)
	{
		printf("Invalid position ");
		return head;
	}

	if(temp->next != NULL)
	{
		temp->next->prev = temp->prev;

	}
	if(temp->prev != NULL)
	{
		temp->prev->next = temp->next;
	}

	free(temp);
	return head;
}


void display(struct node* head)
{
	if(head == NULL)
	{
		printf("List is empty : ");
		return;
	}

	struct node* temp= head;
	printf("Doubly linked list : ");
	while(temp != NULL)
	{
		printf("%d <-> ",temp->data);
		temp = temp->next;
	}

	printf("NULL\n");
}


void search(struct node* head, int value)
{
	struct node* temp = head;
	int position = 1;

	while(temp !=NULL)
	{
		if(temp->data == value)
		{
			printf("Element %d found at position %d\n",value,position);
			return;
		}

		temp = temp->next;
		position++;
	}

	printf("Elment %d not found in the list \n",value);
}


int main()
{

	struct node* head = NULL;
	int choice , data, position, value;

	while(1)
	{
		printf("Menu");
		printf("\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Search\n6.Exit\n");
		printf("Enter your choice ");
		scanf("%d",&choice);


		switch(choice)
		{

			case 1:
				head = create(head);
				break;
			case 2:
				head = insert(head);
				break;
			case 3:
				printf("Enter the position to delete : ");
				scanf("%d",&position);

				head = delete(head,position);
				break;
			case 4:
				display(head);
				break;
			case 5:
				printf("Enter the value to search : ");
				scanf("%d",&value);

				search(head, value);
				break;

			case 6:
				printf("Exiting ..\n");
				exit(0);
			default:

				printf("Invalid choice ! Please try again and enter choice between 1 to 6 ");
		}
	}

	return 0;
}



