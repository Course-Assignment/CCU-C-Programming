#include<stdio.h>

void printStar(int x);

int main()
{	
	int data[1000] = {0};
	int dataSize = 0;
	int i;

	while(scanf("%d", &data[dataSize]) != EOF)
	{
		++dataSize;			
	}
	for(i = 0; i < dataSize; ++i)
	{
		printf("-- n = %d --\n", data[i]);
		printStar(data[i]);
		printf("\n");
	}
	return 0;
}

void printStar(int x)
{
	if(x < 3)
	{
		printf("please enter an odd number more than 3\n");		
	}
	else if(x%2 == 0)
	{
		printf("n is not an odd number\n");		
	}
	else
	{
		int spaceMax = (x-1)/2;
		int spaceMin = 0;
		int space, layer, i;

		space = spaceMax;
		layer = spaceMin;
		while(space != spaceMin)
		{	
			for(i = 0; i < space; ++i)
			{
				printf(" ");		
			}
			for(i = 0; i < (layer*2)+1; ++i)
			{
				printf("*");			
			}
			printf("\n");
			++layer;
			--space;
		}

		for(i = 0; i < x; ++i)
		{
			printf("*");
		}
		printf("\n");

		
		space = spaceMin;
		layer = spaceMax;
		while(space != spaceMax)
		{	
			for(i = 0; i < space+1; ++i)
			{
				printf(" ");		
			}
				for(i = 0; i < (layer*2)-1; ++i)
			{
				printf("*");			
			}
			printf("\n");
			--layer;
			++space;
		}		
	}
}
