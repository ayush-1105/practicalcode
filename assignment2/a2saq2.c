#include<stdio.h>
#include<stdlib.h>

struct student
{
	 int roll_no;
	 char nm[20];
	 int class;
	 float per;
};

int main()
{
	struct student data[50];
	FILE*fptr;
	int roll,i,a;

	fptr=fopen("student1.txt","r");

	while(fscanf(fptr,"%d%s%f%d",&data[i].roll_no,data[i].nm,&data[i].per,&data[i].class)==4)
	{
		i++;
	}

	printf("\n Enter the roll number of student for serching the details:");
	scanf("%d",&roll);
	
	int j;
	for(j=0;j<i;j++)
	{
		if(data[j].roll_no == roll)
		{
			printf("\n STUDENT IS FOUND AND HIS DETAILS IS HERE ");
			printf("\n NAME:%s \t ROLL NUMBER:%d \t CLASS:%d \t PERCENTAGE:%f",data[j].nm,data[j].roll_no,data[j].class,data[j].per);
			break;
		}
		/*
		else
		{
			printf("\n DATA NOT FOUND");
		}*/
	}

	printf("\n DETAILS OF STUDENT WHICH HAVE MAXIMUM PERCENTAGE");

	float max=0;
	for(j=0;j<i;j++)
	{
		if(data[j].per > max)
		{
			max=data[j].per;
			a=j;
		}

	}
	printf("\n NAME:%s \t ROLL NUMBER:%d \t CLASS:%d \t PERCENTAGE:%f",data[a].nm,data[a].roll_no,data[a].class,data[a].per);

	fclose(fptr);


}




