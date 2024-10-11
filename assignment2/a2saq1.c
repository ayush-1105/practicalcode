

#include<stdio.h>
#include<stdlib.h>

int main(){


	int n,class,roll;
	char name[20];

	float per;

	printf("\nEnter the Number of students ");
	scanf("%d",&n);

	FILE* fptr;

	fptr = fopen("student.txt","w");

	if(fptr == NULL)
	{
		printf("\nNot Possible ");
		exit(0);
	}

	for(int i = 0; i< n; i++)
	{
		printf("\nEnter the Roll no: ");
		scanf("%d",&roll);

		printf("\nEnter the name of the student : ");
		scanf("%s",name);
		
		printf("\nEnter the percentage of the student : ");
		scanf("%d",&class);

		printf("Enter the class ");
		scanf("%f",&per);

		fprintf(fptr, "%d %s %d %f\n",roll,name,class,per);


	}

	fclose(fptr);

	fptr = fopen("student.txt","r");

	if(fptr == NULL)

	{

		printf("Not possible ");

		exit(0);
	}


	printf("\n%-10s%-10s%-25s%-15s%\n","Roll No","Name","Percent","Class");


	while(fscanf(fptr,"%d%s%d%f",&roll,name,&class,&per) ==4)
	{
		printf("\n%-10d%-10s%-25d%-15f\n",roll,name,class,per);

	}
	fclose(fptr);
}

