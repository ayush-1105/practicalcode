#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void generate(int a[],int n)
{
	for(int i = 0; i<n; i++)
	{
		a[i] = rand() % 100;
	}
}


void bubbleSort(int a[],int n)
{
	
	for(int i = 0; i < n-1 ; i++)
	{
		for(int j = 0; j < n-i -1; j++)
		{
			if(a[j] > a[j +1]) 
			{
				int temp = a[j];
				a[j] = a[j +1];
				a[j+1] = temp;	
			}
		}
	}
}


void binarySearch(int a[], int n, int x)
{
	
	int left = 0, right = n-1, found = 0;
	while(left <= right) 
	{
		int 	mid = (left + right) /2;
	//	mid = left + (right -left) / 2;
		if(a[mid] ==x)
		{
			printf("The element is at %d index \n",mid);
			found++;

			int i = mid + 1;
			while(a[i] == x)
			{
				printf("The element is at %d index \n",i);
				i++;
			}
			i = mid -1;
			while(a[i] == x)
			{
				printf("The element is at %d index \n",i);
				i--;
			}
			return;

		}

		if(a[mid] < x)
		{
			left = mid + 1;

		}
		else
		{
			right = mid -1;
		}

	}
	if(found == 0)
	{
		printf("The element is not present in the array ");
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
	bubbleSort(arr,n);
	printf("Sorted array : ");
	for( int i = 0; i< n; i++)
	{
	
		printf("%d ",arr[i]);
	}
	printf("\nEnter a number to search : ");
	scanf("%d",&x);
	

 binarySearch(arr,n,x);
/*
	if(index != -1)
	{
		printf("Value %d found at index %d \n",x,index);
	}
	else
	{
		printf("Value %d not found in the array \n",x);
	}
*/
	free(arr);
	return 0;
}
