#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void merge(int arr[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = 0;
	
	int temp[100];


	while( i <= mid && j <= right)
	{
		if(arr[i] <= arr[j])
		{

			temp[k] = arr[i];
			i++;
		}	
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;


	}
	while(i <= mid)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}
	while(j <= right)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}
	for( k = 0; k < right-left +1;k++)
	{
		arr[left + k] = temp[k];
	}
}

void mergeSort(int arr[],int left,int right)
{
	if(left < right)
	{

		int mid = (left + right )/ 2;
		mergeSort(arr,left,mid);
		mergeSort(arr, mid+1, right);

		merge(arr,left,mid,right);
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

	
	mergeSort(arr,0,n-1);

	printf("Sorted array in ascending order : \n ");
	for(int i = 0; i< n; i++)
	{
		printf("%d ",arr[i]);
	}

	return 0;
}
