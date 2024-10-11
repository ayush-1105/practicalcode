
// 
#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data; 
	struct node* next;
};


struct node* createNode(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


struct node* create(struct node* head)
{
	int n , data;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{

		printf("Enter the data for node %d : ", i+ 1);
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
		}
	}
	return head;
}




struct node* insertAtStart(struct node* head, int data)
{

	struct node*  newNode = createNode(data);
	newNode->next = head;
	head = newNode;
	return head;
}


struct node* insertAtEnd(struct node* head, int data)
{
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
		temp->next =  newNode;
	}
	return head;
}	



struct node* insertAtPosition(struct node* head , int data, int position)
{
	struct node* newNode = createNode(data);
	if(position == 1)
	{
		newNode->next = head;
		head = newNode;
		return head;
	}

	struct node* temp = head;

	for(int i = 1; i < position -1 && temp != NULL; i++)
	{
		temp = temp->next;
	}

	if(temp == NULL)
	{
		printf("Invalid position to insert the data ");
		free(newNode);
	}
	else{
		newNode->next = temp->next;
		temp->next = newNode;
	}

	return head;
}


struct node* deleteNode(struct node* head, int value)
{
	if(head == NULL)
	{
		printf("Linked list is empty \n");
		return head;
	}

	struct node* temp = head;
	struct node* prev = NULL;

	if(temp != NULL && temp->data == value)
	{
		head = temp->next;
		free(temp);
		printf("Node with %d value deleted ",value);
		return head;
	}

	while(temp != NULL && temp->data != value)
	{
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL)
	{
		printf("Node with value %d not found ",value);
		return head;
	}

	prev->next = temp->next;
	free(temp);
	printf("Node with value %d deleted ",value);
	return head;
}

void display(struct node* head)

{
	if(head == NULL)
	{
		printf("List is empty");

		return;
	}
	struct node* temp = head;
	printf("Linked list : ");
	while(temp != NULL)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}

	printf("NULL ");


	
}


struct node* insert(struct node* head)
{
	int data, choice, position;
	printf("Enter data to insert : ");
	scanf("%d",&data);

	printf("\nWhere do you want to insert ");
	printf("1.At the start \n2.At the end \n3.At a specific position \n");
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
			printf("Enter the position " );
			scanf("%d",&position);
			head = insertAtPosition(head, data, position);

			break;
		default: 
			printf("Invalid choice \n");

	}
	return head;
}

int main()
{

	struct node* head = NULL;
	int choice , value;
	

	while(1)
	{

		printf("\nMenu \n");
		printf("1.Create \n2.Insert \n3.Delete\n4.Display\n5 Exit\n");

		printf("Enter your choice : ");
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
				printf("Enter the value to delete : ");
				scanf("%d",&value);

				head = deleteNode(head, value);
				break;
			case 4: 
				display(head);
				break;
			case 5: 
				printf("Exiting ..\n");
				exit(0);
			default:
				printf("Invalid choice ! Please try again And please enter the between 1 to 5 ");

		}
	}
	return 0;
}



