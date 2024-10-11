#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct employee 
{
	char name[40];
	int age;
};


void writeData(int n)
{
	FILE *file = fopen("employee.txt","w");
	if(file == NULL)
	{
		printf("Error in opening the file ");
		exit(1);
	}

	struct employee emp;
	for(int i = 0; i < n;i++){

		printf("Enter name of the employee %d : ",i+1);
		scanf("%s",emp.name);
		printf("Enter age of the employee %d : ",i+1);
		scanf("%d",&emp.age);

		fprintf(file,"%s %d",emp.name,emp.age);
	}

	fclose(file);

}


void readData(struct employee emp[],int n)
{
	FILE *file = fopen("employee.txt","r");
	if(file == NULL)
	{
		printf("\nError in opening the file ");
		exit(1);
	}

	for(int i = 0; i< n; i++)
	{
		fscanf(file,"%s %d",emp[i].name, &emp[i].age);
	}
	fclose(file);
}


void bubbleSort(struct employee emp[],int n)
{
	for(int i = 0; i < n- 1; i++)
	{

		for(int j = 0; j < n-1 - i; j++)
		{
			if(emp[j].age > emp[j+1].age)
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
	printf("Enter the number of employee data you want to enter : ");
	scanf("%d",&n);

	int arr[100];

	struct employee emp[100];
	writeData(n);

	readData(emp,n);

	bubbleSort(emp,n);
	printf("\nEmployee data sorted by age using bubble sort ");

	displayEmp(emp,n);
}
