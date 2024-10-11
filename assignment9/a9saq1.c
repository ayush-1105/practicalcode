#include<stdio.h>


void swap(int *a, int*b)
{
	int temp = *a;
	*a = *b;
       *b = temp;	
}

void heapify(int arr[], int n, int i)
{

	int large = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && arr[left] > arr[large])
	{
		large = left;
	}

	if(right < n && arr[right] > arr[large])
	{

		large = right;
	}

	if(large != i)
	{
		swap(&arr[i],&arr[large]);
		heapify(arr, n, large);
	}
}


void heapSort(int arr[], int n)
{
	
	for(int i = n/2 - 1; i >=0; i--)
	{
		heapify(arr, n , i);
	}

	for(int i = n - 1;i > 0; i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr, i ,0);
	}
}


void printArray(int arr[], int n)
{

	for(int i = 0; i < n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{

	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);


	int arr[n];
	printf("Enter %d elements : ",n);
	for(int i = 0; i < n; i++)
	{
	
		scanf("%d",&arr[i]);
	}

	heapSort(arr,n);

	printf("Sorted array : ");
	printArray(arr, n);

	return 0;

}
