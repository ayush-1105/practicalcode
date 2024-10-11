#include<stdio.h>

int folding(int key, int table_size)
{

	int sum = 0;

	while(key > 0)
	{

		sum += key % 1000;
		key /= 1000;
	}

	return sum % table_size;
}


int main()
{

	int keys[] = {21982432, 213432183, 343541652, 542313753};
	int table_size = 1000;
	int n = sizeof(keys) / sizeof(keys[0]);

	printf("Key\t\tHash Address\n");

	for(int i = 0; i < n;i++)
	{

		int hash_address = folding(keys[i], table_size);
		printf("%d\t%d\n", keys[i], hash_address);

	}
	return 0;
}
