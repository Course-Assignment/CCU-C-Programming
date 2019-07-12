#include<stdio.h>

double UpperLower_Rate(int uppercase, int lowercase)
{
	double rate;
	if(lowercase == 0)
	{	
		uppercase = 0;
		lowercase = 1;
	}
	rate = uppercase*1.0/lowercase;
	return rate;
}

double DigitAlphabet_Rate(int digit, int alphabet)
{
	double rate;
	if(alphabet == 0)
	{
		digit = 0;
		alphabet = 1;
	}
	rate = digit*1.0/alphabet;
	return rate;	
}

void getReverse(char text[], int size)
{
	int i;
	for(i = size-1; i >= 0; i--)
	{
		printf("%c", text[i]);
	}
	printf("\n");
}			

int main()
{
	int c, i;
	int uppercase, lowercase, digit, alphabet, size;
	uppercase = lowercase = digit = alphabet = size = 0; 
	
	char text[1000] = {0};

	while((c=getchar()) != EOF)
	{
		if(c >= 'a' && c <= 'z')
		{
			lowercase++;
			alphabet++;
			text[size] = c;			
		}
		else if(c >= 'A' && c <= 'Z')
		{
			uppercase++;
			alphabet++;
			text[size] = c;		
		}
		else if(c >= '0' && c <= '9')
		{
			digit++;
			text[size] = c;
		}
		else
		{
			text[size] = c;
		}
		size++;
	}
	
	printf("Uppercase / Lowercase : %.3f\n", UpperLower_Rate(uppercase, lowercase));	
	printf("Digit / Alphabet : %.3f\n", DigitAlphabet_Rate(digit, alphabet));
	printf("--- Reverse ---\n");
	getReverse(text, size);
	return 0;
}
