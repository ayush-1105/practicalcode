#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct employee 
{
	char name[40];
	int age;
};




void readData(struct employee emp[],int *n)
{
	FILE *file = fopen("employee.txt","r");
	if(file == NULL)
	{
		printf("\nError in opening the file ");
		exit(1);
	}

	int i = 0;
	while(fscanf(file,"%s %d",emp[i].name,&emp[i].age) != EOF)
{
	i++;
}
	*n = i;
	fclose(file);
}


void bubbleSort(struct employee emp[],int n)
{
	for(int i = 0; i < n- 1; i++)
	{

		for(int j = 0; j < n-1 - i; j++)
		{
			if(strcmp(emp[j].name,emp[j+1].name) > 0)
			{

				struct employee temp = emp[j];
				emp[j] = emp[j + 1];
				emp[j +1] = temp;
			}
		}
	}
}


void displayEmp(struct employee emp[], int n)
{
	printf("\nSorted Employee data \n");
	for(int i = 0; i < n; i++)
	{
		printf("Name : %s , Age  : %d\n", emp[i].name , emp[i].age);
	}
}


int main()
{
	int n;
	

	struct employee emp[100];
	

	readData(emp,&n);

	bubbleSort(emp,n);
	printf("\nEmployee data sorted by age using bubble sort ");

	displayEmp(emp,n);
}
