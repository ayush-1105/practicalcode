#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct books {

	char title[50];
	char author[50];
	char bookType[100];
	int book_id;
	int no_of_copies;
	float cost;
	char bookMonth[40];

};



void displayReference(struct books book[], int total)
{
	int i ;
	char totals[10];
	printf("Enter the books type you want to display : ");
	scanf(" %s",&totals);

	for(i = 0; i < total; i++)
	{
		if((strstr(book[i].bookType,"r")))
		{

			printf("\n All the reference book :");
			printf("\nBook id: %d\nBook name : %s \n Month name : %s \n Book type : %s \n ", book[i].book_id,book[i].title,book[i].bookMonth,book[i].bookType); 
		}
	}

}



void displayMbyMonth(struct books book[], int total)
{
    char month[30];
    printf("Enter the month name of the magazine you want to display: ");
    scanf("%s", month);

    for(int i = 0; i < total; i++)
    {
        if((strcmp(book[i].bookMonth, month) == 0) && (strstr(book[i].bookType, "m")))
        {
            printf("\nDetails of magazine published in the month %s\n", month);
            printf("Book id: %d\n", book[i].book_id);
            printf("Book name: %s\n", book[i].title);
            printf("Month name: %s\n", book[i].bookMonth);
            printf("Book type: %s\n", book[i].bookType);
            printf("----------------------------\n");
        }
    }
}


void calculateCost(struct books book[],int total)

{
	float totalCost = 0.0;
	for(int i = 0; i<total; i++)
	{
	
		totalCost += book[i].cost * book[i].no_of_copies;


			}

	printf("Total cost : %f \n",totalCost);

}
		
int main(){
	


	struct books book[100];

	int ch;
	char month[50];
	int total;
				printf("Enter the total number of book to add : ");
				  scanf("%d",&total);
				  for(int i = 0; i< total; i++) {

				  printf("Enter the book title of book %d : " ,i +1);
				  scanf("%s",book[i].title);
				  
				  printf("Enter the author name : ");
				  scanf("%s",book[i].author);

				  printf("Enter Book type : ");
				  scanf("%s",book[i].bookType);

				   printf("Enter book id : ");
				  scanf("%d",&book[i].book_id);

				  printf("Enter the month book was published :  ");
				  scanf("%s",book[i].bookMonth);

				  printf("Enter the number of copies : ");
				  scanf("%d",&book[i].no_of_copies);

				  printf("Enter the cost of the books : ");
				  scanf("%f",&book[i].cost);
				  }

	while(1)
	{
		printf("Menu :\n");
		
		printf("1. Display all reference books \n");
		printf("2. Search magazine by month  \n");
		printf("3. Calculate total cost of all books  \n");
		printf("4. Exit \n");

		printf("Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)  {

			  case 1:
				  displayReference(book,total);
				  
				break;
			case 2:
				displayMbyMonth(book,total);
				break;
			case 3:
				calculateCost(book,total);
				break;
			case 4:
				return 0;
			default: 
				printf("Enter the number between 1 to 4 ");
						 }
		


	}	
}

