#include<stdio.h>
#include<math.h>


int midsquare(int key, int table_size)
{


	long long square = (long long)key + key;
	int num_digits = log10(square) + 1;
	int middle_digits;

	if(num_digits > 3)
	{


		int shift_amount = (num_digits - 3)/2;

		middle_digits = (square / (int)pow(10,shift_amount )) % 1000;
	}

	else
	{

		middle_digits = square % 1000;
	}

	return middle_digits % table_size;
}

int main()
{

	int keys[] = {342,213,432, 542, 132, 763,298};

	int table_size = 1000;
	int n = sizeof(keys) / sizeof(keys[0]);

	printf("Key\tHash Address\n");

	for(int i = 0; i < n; i++)
	{

		int hash_address = midsquare(keys[i],table_size);
		printf("%d\t%d\n",keys[i], hash_address);

	}
	return 0;
	
}
