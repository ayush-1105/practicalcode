//
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct city
{
	char name[50];
	int population;
	float literacy;
};



// code to enter the detais of the city
//
//
void inputCity(struct city *c, int n)
{
	for(int i = 0; i < n ; i++)
	{
		printf("Enter the details for the city : %d \n",i +1);

		printf("Enter city Name : ");
		scanf(" %[^\n]s", c[i].name);

		printf("Enter population : ");

		scanf("%d",&c[i].population);

		printf("Enter literacy percentage : ");
		scanf("%f",&c[i].literacy);

	}
}


void listLiteracy(struct city *c, int n)
{
	printf("Literacy details of all cities : \n");
	for(int i = 0; i < n; i++)
	{
		printf("\nCity %d : ", i +1);
		printf("City Name :  %s \n",c[i].name);
		printf("Literacy Percentage : %f \n",c[i].literacy);
	}

}


void displayMax(struct city *c, int n)
{
	int max = 0;
	for(int i = 1; i < n ;i++)
	{
		if(c[i].population > c[max].population)
		{
			max = i;
		}
	}

	printf("\n City with the maximum population :  ");
	printf("City Name : %s \n",c[max].name);
	printf("Population : %d \n ",c[max].population);
	printf("Literacy Percentage : %f ",c[max].literacy);



}



void displaySpecific(struct city *c, int n, char *cityName)
{
	for(int i = 0; i< n; i++)
	{
		if(strcmp(c[i].name,cityName) == 0)
		{
			printf("\nDetails of city  \n");
			printf("\nCity Name : %s \n Population : %d \n Literacy Percenatage : %f ",c[i].name,c[i].population,c[i].literacy);
			return;
		}
	}
	printf("City %s not found ",cityName);



}
int main()
{

	int n , ch;
	char cityName[50];

	printf("Enter the number of cities : ");
	scanf("%d",&n);


	struct city c[100];

	inputCity(c,n);
	
	do
	{
		printf("\n 1. List literact details of all cities :  \n");
		printf("\n 2. Display city with maximum populations : \n");
		printf("\n 3. Display details of a specific city : \n ");

		printf("\n 4. Exit \n");

		printf("Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				listLiteracy(c,n);
				break;
			case 2: 
				displayMax(c,n);
				break;
			case 3:
				printf("Enter the City Name to search ");
				scanf("%s", cityName);
				displaySpecific(c,n,cityName);
				break;
			case 4:
				printf("Exiting.... \n");
				exit(0);
			default:
				printf("Invalid choice , Try again ");
				break;
		}
	
	}while(ch !=4);

	return 0;

}

