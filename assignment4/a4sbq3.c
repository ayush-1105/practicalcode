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

int partition(struct employee emp[], int low, int high)
{
	int pivot = emp[high].age;
	int i = ( low - 1);

	for( int j = low; j < high; j++)
	{
		if(emp[j].age < pivot)
		{
			i++;
			struct employee temp = emp[i];
			emp[i] = emp[j];
			emp[j] = temp;
		}
	}

	struct employee temp = emp[i + 1];
	emp[i + 1] = emp[high];
	emp[high] = temp;

	return (i + 1);
}


void quickSort(struct employee emp[],int low, int high)
{
	if(low < high)
	{
		int pi = partition(emp,low,high);

		quickSort(emp , low, pi -1);
		quickSort(emp , pi + 1, high);
	}
}




void writeSorted(struct employee emp[],int n, const char *filename){
	FILE *file =  fopen(filename,"w");

	if(file == NULL)
	{
		printf("Error in opening the file for sorted part ");
		exit(1);
	}

	for(int i = 0; i < n; i++)
	{
		fprintf(file,"%s %d\n",emp[i].name,emp[i].age);
	}

	fclose(file);
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

	quickSort(emp,0,n-1);
	writeSorted(emp,n,"sortedemponage.txt");
	printf("\nEmployee data sorted by age using  quick  sort ");

	displayEmp(emp,n);
}
