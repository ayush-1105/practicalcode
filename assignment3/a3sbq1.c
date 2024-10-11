#include<stdio.h>
#include<string.h>


int main()
{
	int n, stdCode;
	char city[30],  citySearch[20];

	FILE *fptr;
	fptr = fopen("cities.txt","w");
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
		scanf("%s",city);

		printf("Enter the STD code : ");
		scanf("%d",&stdCode);

		fprintf(fptr, "%s %d\n",city,stdCode);


	}

	fclose(fptr);

	fptr = fopen("cities.txt","r");
	if(fptr == NULL)
	{
		printf("Error in opening the file :");
		return 1;
	}
	printf("\nEnter the name of the city you want to search : ");
	scanf("%s",citySearch);

	int found = 0;
	while(fscanf(fptr, "%s %d",city,&stdCode) == 2)
	{
		if(strcmp(citySearch,city) == 0) 
		{
			
		     printf("\nCity Found, STD Code is %d\n",stdCode);
		
		found = 1;
		break;
		}
	}

	if(found == 0)
	{
		printf("\nThe city is not present \n");
	}

	fclose(fptr);
	return 0;
}
