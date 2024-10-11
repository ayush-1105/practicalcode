#include<stdio.h>

#include<stdlib.h>




void writeFile(const char *filename, int *numbers, int count)

{

	FILE *file = fopen(filename,"w");
	if(file == NULL)
	{
		printf("Error while writing ");
		exit(1);
	}

	for(int i =0; i< count; i++)
	{
		fprintf(file,"%d\n",numbers[i]);
	}
	fclose(file);
}
int main()
{
	int numbers[100];
	int n;

	printf("ENter the number of intergers to enter : ");

	scanf("%d",&n);

	if(n > 100)
	{
		printf("The number above 100 is not allowed ");

		return 1;
	}

	printf("Enter %d integers : \n",n);
	for(int i = 0; i < n;i++)
	{
		scanf("%d",&numbers[i]);
	}

	int evenN[100];
	int oddN[100];

	int evenC= 0, oddC = 0;

	for(int i = 0; i < n; i++)
	{
		if(numbers[i] %2 == 0)
		{
			evenN[evenC++] = numbers[i];

		}
		else
		{
			oddN[oddC++] = numbers[i];
		}
	}

	writeFile("Even.txt",evenN,evenC);
	writeFile("Odd.txt",oddN,oddC);

	printf("Even and odd numbers have been written in  the file ");
	return 0;
}
