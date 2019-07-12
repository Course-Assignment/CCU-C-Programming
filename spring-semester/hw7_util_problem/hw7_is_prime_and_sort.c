#include<stdio.h>
#include<math.h>

#define TRUE   1
#define FALSE  0

//int convertSqrt(int x);
int isPrime(int x);
void sort(int data[], int dataSize);


int main()
{
	int input, dataSize;
	input = dataSize = 0;
	int i;
	int data[1000];

	while((scanf("%d", &input) != EOF))
	{
		data[dataSize] = input;
		dataSize++;
	}
	
	printf("-- isPrime --\n");
	for(i = 0; i < dataSize; i++)
	{
		printf("%d: ",data[i]);

		if(isPrime(data[i]) == TRUE)
		{	
			printf("yes\n");
		}
		else if(isPrime(data[i]) == FALSE)
		{
			printf("no\n");	
		}
	}
	sort(data, dataSize);

	return 0;
}

/*
int convertSqrt(int x)
{
	double sqrt;
	int i;

	for(i = 0; i < 10; i++)
	{	
		sqrt = 0.5*(sqrt+(x/sqrt));
	}

	return (int)sqrt; 
}
*/

int isPrime(int x)
{
	if(x > 3)
	{
		if(x%2 == 0 || x%3 == 0)
		{
			return FALSE;	
		}
		else
		{
			int i; 
			int root = (int)sqrt(x);
			for(i = 5; i < root; i+=2)
			{
				if(x%i == 0)
				{
					return FALSE;	
				}
			}
			return TRUE;
		}
	}
	else if(x == 2 || x == 3)
	{
		return TRUE;		
	}
	else if(x < 2)
	{
		return FALSE;
	}
	return 0;
}

void sort(int data[], int dataSize)
{
	int i, j;
	
	for(j = 0; j < dataSize; j++)
	{
		for(i = 0; i < dataSize-1-j; i++)
		{
			if(data[i] > data[i+1])
			{
				int temp = 0;
				temp = data[i+1];
				data[i+1] = data[i];
				data[i] = temp;
			}
		}
	}
	
	printf("\n-- Sort --\n");
	for(i = 0; i < dataSize; i++)
	{
		printf("%d\n", data[i]);		
	}
}

