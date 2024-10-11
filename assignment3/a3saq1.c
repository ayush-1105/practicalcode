#include<stdio.h>

#include<stdlib.h>
#include<time.h>



void generate(int *a,int n)
{
	for(int i = 0; i<n; i++)
	{
		a[i] = rand() % 100;
	}
}

void linearS(int *a, int n,int x)
{
	int found = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
		{

			printf("The element found at %d index \n",i);
		}
	}

	if(found == 0)
	{
		printf("The element not found ");
	}
}

int main()
{
	int  n,x,index;
	printf("Enter the number of elements in the arrray : ");
	scanf("%d",&n);


	int *arr = (int *)malloc(n * sizeof(int));
	if(arr == NULL)
	{
		printf("Memory allocation failed try again");
		return 1;
	}

	srand(time(0));
	generate(arr,n);

	printf("Generated array ");

	for(int i = 0; i < n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	printf("Enter a number to search : ");
	scanf("%d", &x);

	linearS(arr,n,x);

	

	free(arr);
	return 0;
}
