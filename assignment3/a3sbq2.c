#include<stdio.h>
#include<string.h>



typedef struct
{
	char name[30];
	int stdCode;
}City;



void bubbleSort(City c[],int n)
{
	for(int i = 0; i< n; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(strcmp(c[j].name,c[j+1].name) > 0)
			{
				City temp = c[j];
				c[j] = c[j + 1];
				c[j +1] = temp;
			}
		}
	}
}


int binarySearch(City c[], int n , char *target)
{
	int left = 0, right = n -1;
	while (left <= right) 
	{
		int mid = (left + right )/ 2;
		int cmp = strcmp (c[mid].name, target);

		if(cmp == 0)
		{

			return mid;
		}
		else if(cmp < 0)
		{

			left = mid + 1;
		}
		else {
			right = mid -1;
		}
	}
	return -1;

}

int main()
{
	int n, stdCode;
	char  citySearch[20];
	City c[20];


	FILE *fptr;
	fptr = fopen("cities1.txt","w");
	if(fptr == NULL)
	{
		printf("Error in opening the file : ");
		return 1;
	}

	printf("\n Enter the number of cities you want to enter : ");
	scanf("%d",&n);

	for(int i = 0; i< n; i++)
	{
		printf("\nEnter the city name of %d : ",i + 1);
		scanf("%s",c[i].name);

		printf("Enter the STD code : ");
		scanf("%d",&c[i].stdCode);

      		fprintf(fptr, "%s %d\n",c[i].name,c[i].stdCode);


	}

	fclose(fptr);

	fptr = fopen("cities1.txt","r");
	if(fptr == NULL)
	{
		printf("Error in opening the file :");
		return 1;
	}
	
	n = 0;
	while(fscanf(fptr, "%s %d",c[n].name,&c[n].stdCode) ==2)
	{
		n++;
	
	}
	fclose(fptr);

	bubbleSort(c,n);

	fptr = fopen("sortedcities.txt","w");
	if(fptr == NULL)
	{
		printf("Error in opening the file ");
		return 1;
	}

	for(int i = 0; i < n; i++)
	{

		fprintf(fptr, "%s %d\n",c[i].name,c[i].stdCode);
	}

	fclose(fptr);

	printf("\nEnter the name of the city you want to search : ");
	scanf("%s",citySearch);

	int found = binarySearch(c,n,citySearch);

	if(found != -1)
	{

		printf("\nCity found ,STD Code is %d\n",c[found].stdCode);
	}
	else {
		printf("\nThe city is not present \n");
	}

	return 0;
}
