

//
#include<stdio.h>
#include<stdlib.h>


struct student
{
	int rollNo;
	char name[20];
	float percentage;
	struct marks
	{
		int sub1;
		int sub2;
		int sub3;
	}marks;
};

int validate(int marks)
{
	return (marks >= 0 && marks <=100);
}

void calculate(struct student *s)
{
	float totalmarks = s->marks.sub1 + s->marks.sub2 + s->marks.sub3;
	s->percentage = totalmarks / 3.0;
}


void display(struct student *s,int n)
{
	printf("Print student details " );
	for(int i = 0; i < n; i++)
	{

		printf("Student number:  %d \n roll no : %d\n Name : %s \n marks of sub1 : %d \n marks of sub2 : %d \n marks of sub3 %d \n Percent : %f",i+1,s[i].rollNo,s[i].name,s[i].marks.sub1,s[i].marks.sub2,s[i].marks.sub3,s[i].percentage);
	}
}
void stuInput(struct student *s, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("Enter the details of student : %d ",i +1);
		printf("Enter roll no ");
		scanf(" %d",&s[i].rollNo);

		printf("Enter Name : ");
		scanf(" %s", &s[i].name);


		do
		{
			printf("Enter marks of sub 1 : ");
			scanf(" %d", &s[i].marks.sub1);
			if(!validate(s[i].marks.sub1))
			{
				printf("Marks is not valid ");
			}

		}while(!validate(s[i].marks.sub1));
		do {
                        printf("Enter marks of sub 2 : ");
                        scanf(" %d", &s[i].marks.sub2);
                        if(!validate(s[i].marks.sub2))
                        {
                                printf("Marks is not valid ");
                        }

                }while(!validate(s[i].marks.sub2));
		do
                {
                        printf("Enter marks of sub 3 : ");
                        scanf(" %d", &s[i].marks.sub3);
                        if(!validate(s[i].marks.sub3))

                        {
                                printf("Marks is not valid ");
                        }

                }while(!validate(s[i].marks.sub3));

	calculate(&s[i]);
	}

}


// code for seaching the student using there roll numbers
//
///
void searchStudent(struct student s[],int n)
{
	int rollno;
	printf("Enter Roll number to search : ");
	scanf(" %d",&rollno);

	for(int i = 0; i < n; i++)
	{
		if(s[i].rollNo == rollno) {
		printf("\nROll no: %d \n Name : %s Marks : \n sub1 : %d \n sub2 : %d \n sub3 : %d \n Percentage : %f",s[i].rollNo,s[i].name,s[i].marks.sub1,s[i].marks.sub2,s[i].marks.sub3,s[i].percentage);
		return;

	}
	}
	printf("Student with Roll Number  %d not found ",rollno);

};


void modifyStudent(struct student *s,int n)
{
	int rollno;
	printf("Enter rollno of the student to modify : ");
	scanf(" %d",&rollno);

	for(int i = 0; i < n; i++)
	{
		if(s[i].rollNo == rollno)
		{
			printf("Enter New name : ");
			scanf("%s",s[i].name);
			printf("Enter new marks of 3 subject : ");
			
			
				scanf("%d%d%d",&s[i].marks.sub1,&s[i].marks.sub2,&s[i].marks.sub3);
				if(!validate(s[i].marks.sub1) || !validate(s[i].marks.sub2) || !validate(s[i].marks.sub3))
				{
					printf("Invalid marks ,Enter the correct marks between 0 and 100 to confirm ");
					
				}
			
			calculate(&s[i]);
			return;
		}
	}
	printf("Student whose rollno is %d , not found \n",rollno);
}


//
//
//
//
void displayCondition (struct student *s,int n)
{
	float percentage;
	printf("Enter the percentage to filter ");
	scanf(" %f",&percentage);

	for(int i = 0; i < n; i++)
	{
		if(s[i].percentage > percentage)
		{
			printf("\nROll no: %d \n Name : %s Marks : \n sub1 : %d \n sub2 : %d \n sub3 : %d \nPercentage : %f",s[i].rollNo,s[i].name,s[i].marks.sub1,s[i].marks.sub2,s[i].marks.sub3,s[i].percentage);
		}
	}	
}


void displayMax(struct student *s,int n)
{
	int  max = 0;
	for (int i = 1; i < n; i++)
	{
		if(s[i].percentage > s[max].percentage)
		{
			max = i;
		}
	}

	printf("Student with highest percentage : \n");
	printf("\nROll no: %d \n Name : %s Marks : \n sub1 : %d \n sub2 : %d \n sub3 : %d \nPercentage : %f",s[max].rollNo,s[max].name,s[max].marks.sub1,s[max].marks.sub2,s[max].marks.sub3,s[max].percentage);
}
void searchStudent(struct student *s, int n);
int main()

{
	int n,ch;
	printf("Enter the total data to enter : ");
	scanf("%d", &n);

	struct student s[100];
	stuInput(s,n);

	display(s,n);


	do
	{
		printf("\nEnter Your choice to contine : ");
		printf("\n1 Search student according to the roll number : ");
		printf("\n2 Modify details of student (accept roll number : ");
		printf("\n3 Display all student details : ");
		printf("\n4 Display all student having percentage > : ");
		printf("\n5 Display student(s) having maximum percentage : ");

		printf("\n 6 exit ");

		printf("Enter your choice ");
		scanf("%d",&ch);
/*
		switch(ch)
		{
			case 1: 
				searchStudent(s,n);
				break;
			case 2: 
				modifyStudent();
				break;
			case 3: 
				display(s,n);
				break;
			case 4: 
				displayCondition();
				break;
			case 5:
				displayMax();
				break;
			default:
				printf("\nEnter valid choice ");
			


		}*/

		switch(ch)
		{
			case 1:
				searchStudent(s,n);
				break;
			case 2: 
				
				modifyStudent(s,n);
				break;		
		
			case 3:
				display(s,n);
				break;
			case 4:
				displayCondition(s,n);
				break;
			case 5:
				displayMax(s,n);
				break;
			case 6: 
				exit(0);

			default:
				printf("Invalid choice ");
		}
	}while(ch !=5);



}
