#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int arr[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j -1;
		}
		arr[j + 1 ] = key;

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
		printf("%d",arr[i]);
	}

	printf("\n");

	
	insertionSort(arr,n);

	printf("Sorted array in ascending order : \n ");
	for(int i = 0; i< n; i++)
	{
		printf("%d ",arr[i]);
	}

	return 0;
}
