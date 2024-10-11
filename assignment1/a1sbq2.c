//student 

#include<stdio.h>

struct birthDate
{
	int dd;
	int mm;
	int yyyy;
};

struct student

{
	int rno;
	char name[30];
	float per;
	struct birthDate b;
};


int isValid(int dd, int mm, int yyyy);
void acceptDetails(struct student s[],int n);

void displayStudentByMonth(struct student s[],int n, int month);

int main()
{
        int n, month , i;

        printf("Enter the number of students data to be entered : ");
//        scanf(" &d",&n);
	while(scanf("%d",&n) !=1 || n<=0)
	{
		printf("Enter positive");
		while(getchar() != '\n');
	}

        struct student s[100];
	
    acceptDetails(s,n);

        printf("Enter the month between (1-12) to search for the student : ");

        scanf(" %d",&month);


        displayStudentByMonth(s,n,month);

        return 0;

};




void acceptDetails(struct student s[],int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nEnter the details for the student : %d ",i + 1);
		printf("\nRoll number : ");
		scanf(" %d",&s[i].rno);

		printf("\nEnter the Name of the student : ");
		scanf(" %[^\n]s",s[i].name);

		printf("Enter the percentage of the student : ");
		scanf(" %f",&s[i].per);
		

		int valid = 0;

		while(!valid)
		{
			printf("Birthdate  (dd/mm/yyyy) ");

			scanf("%d%d%d",&s[i].b.dd,&s[i].b.mm,&s[i].b.yyyy);
			valid = isValid(s[i].b.dd,s[i].b.mm,s[i].b.yyyy);

			if(!valid) 
			{
				printf("Invalid date , Please try again ");

			}
		}

		
	}	
}



void displayStudentByMonth(struct student s[],int n, int month)
{
	int i, found = 0;

	printf("\n Student with birthdate in month %d : \n ");

	for ( i = 0; i < n; i++)
	{
		if(s[i].b.mm == month)
		{
			printf("\nRoll number : %d \n Name : %s \n Percentage : %f \n Birthdate : %02d/%02d/%02d \n",s[i].rno,s[i].name,s[i].per,s[i].b.dd,s[i].b.mm,s[i].b.yyyy);
		found = 1;
		}
	}
	if(!found)
	{
		printf("No student found with the birthdate in month : %d \n ",month);
	}
};

int isValid(int dd, int mm, int yyyy)
{
	if(yyyy < 1900 || yyyy > 2025) return 0;
	if(mm < 1 || mm > 12) return 0;

	if(dd < 1 || dd > 31) return 0;

	if(mm == 4 || mm == 6 || mm == 9 || mm == 11) 
	{
		if(dd > 30) return 0;
	}

	if(mm == 2)
	{
		if((yyyy % 4 == 0 && yyyy % 100 != 0 ) || (yyyy % 400 == 0))
		{
			if(dd > 29) return 0;

		}
		else 
		{
			if(dd > 28) return 0;
		}	
	}

	return 1;
}

