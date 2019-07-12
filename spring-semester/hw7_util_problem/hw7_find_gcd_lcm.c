#include<stdio.h>

int GCD(int x, int y);
int LCM(int x, int y);

int main()
{
	int firstValue[1000] = {0};
	int secondValue[1000] = {0};
	int arraySize = 0;
	int i;
	
	while((scanf("%d %d", &firstValue[arraySize], &secondValue[arraySize]) != EOF))
	{
		++arraySize;
	}	
	
	for(i = 0; i < arraySize; ++i)
	{
		printf("-- %d, %d --\n", firstValue[i], secondValue[i]);
		printf("GCD = %d\n", GCD(firstValue[i], secondValue[i]));
		printf("LCM = %d\n\n", LCM(firstValue[i], secondValue[i]));
	}	
	return 0;
}

int GCD(int x, int y)
{   
	if(x > 0 && y > 0)
	{
		while(x > 0 && y > 0)
		{
			if(x > y)
			{
				x = x % y;		
			}
			else if(y > x)
			{
				y = y % x; 		
			}
			else if(x == y)
			{
				return x;			
			}
		}
		if(x == 0)
		{
			return y;		
		}
		else if(y == 0)
		{
			return x;		
		}
	}
	else if(x == 0 || y == 0)
	{
		if(x == 0)	
		{
			return y;		
		}
		else if(y == 0)
		{
			return x;
		}
	}
	else if(x == 0 && y == 0)
	{
		return 0;	
	}


	return 0;
}


int LCM(int x, int y)
{
	if(GCD(x,y) == 0)
	{
		return 0;		
	}
	return x*y/GCD(x,y);                           // LCM = (x/GCD)*(y/GCD)*GCD; 
}

