#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high)
{

	int pivot = arr[high];
	int i = (low - 1);
	for( int j = low; j<=high -1; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}	

	swap(&arr[i+1],&arr[high]);
	return(i + 1);
}

void quickSort(int arr[], int low, int high)
{

	if(low< high)
	{
		int pi = partition(arr,low,high);
		
		quickSort(arr,low,pi -1);
		quickSort(arr,pi +1, high);

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

	
	quickSort(arr,0,n-1);

	printf("Sorted array in ascending order : \n ");
	for(int i = 0; i< n; i++)
	{
		printf("%d ",arr[i]);
	}

	return 0;
}
