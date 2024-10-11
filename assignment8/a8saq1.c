

#include "btree.h"

int main()
{

	node* root = NULL;
	int choice , value;

	do
	{

		printf("\nMeny Binary Search tree \n");
		printf("1.Insert\n2.Delete\n3.Search\n4.inOrder Traversal\n5.preOrder Traversal\n6.postOrder Traversal\n7.Exit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{

			case 1:
				printf("Enter the value to insert: ");
				scanf("%d",&value);
				root = insert(root,value);
				printf("Inserted %d.\n",value);
				break;
			case 2:
				printf("(optional)Enter the value to delete : ");
				scanf("%d",&value);
				root = delete(root,value);
				printf("Deleted %d \n",value);
				break;
			case 3:
				printf("Enter value to search : ");
				scanf("%d",&value);
				if(search(root,value))
					printf("Value %d found in the tree \n",value);
				else
					printf("Value %d not found in the tree \n",value);
				break;
			case 4:
				printf("InOrder Traversal : ");
				inOrder(root);
				printf("\n");
				break;
			case 5:
				printf("Preorder Traversal : ");
				preOrder(root);
				printf("\n");
				break;
			case 6:
				printf("Postorder Traversall : ");
				postOrder(root);
				printf("\n");
				break;
			case 7:
				printf("Exiting.... \n");
				break;
			default:
				printf("Invalid choice ! Please enter the choice between 1 to 7 ");
		}
	}while(choice != 7);

	return 0;
}


