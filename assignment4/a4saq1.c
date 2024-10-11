#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int arr[],int n)
{


	for(int i = 0; i < n; i++)
	{
		for(int  j = 0; j < n -i - 1; j++)
		{
			if(arr[j] > arr[j+ 1])
			{
				int temp = arr[j];
				arr[j] = arr[j+ 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	printf("Enter the number size of the array : ");
	scanf("%d", &n);

	int arr[100];

	srand(time(0));
	printf("Random array ");
	for(int i = 0; i < n; i++)
	{

		arr[i] = rand() % 100;
		printf("%d ",arr[i]);
	}

	printf("\n");

	
	bubbleSort(arr,n);

	printf("Sorted array in ascending order : \n ");
	for(int i = 0; i< n; i++)
	{
		printf("%d ",arr[i]);
	}

	return 0;
}
