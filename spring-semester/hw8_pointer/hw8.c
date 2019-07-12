#include<stdio.h>
#include<stdlib.h>

#define IN 1
#define OUT 0
#define FILESIZE 65536

int WordCount(int *data, int totalChar);
int LineCount(int *data, int totalChar);
void Original(int *data, int totalChar);
void ToLowerCase(int *data, int *toLowerCount, int totalChar);

int main()
{	
	int ch;
	int fileSize = FILESIZE;
	int totalChar = 0;
	int toLowerCount = 0;

	int *data = malloc(fileSize*sizeof(int));

	while((ch = getchar()) != EOF)
	{
		data[totalChar++] = ch;
	}
	
	printf("Total character:%d\n", totalChar);
	printf("Word count:%d\n", WordCount(data, totalChar));
	printf("Line:%d\n", LineCount(data, totalChar));
	Original(data, totalChar);
	ToLowerCase(data, &toLowerCount, totalChar);
	printf("--count--\nupper case to lower case:%d", toLowerCount);

	free(data);

	return 0;
}
	
int WordCount(int *data, int totalChar)
{
	int i;
	int state = OUT;
	int wordCount = 0;

	for(i = 0; i < totalChar; i++)
	{
		if(data[i] == ' ' || data[i] == '\n' || data[i] == '\t')		
		{
			if(data[i+1] > 122 || data[i+1] < 65)
			{
				state = IN;		
			}
			else if(data[i+1] > 90 && data[i+1] < 97)
			{
				state = IN;		
			}
			else
			{
				state = OUT;
			}
		}
		else if(state == OUT)
		{
			state = IN;
			wordCount++;
		}
	}

	/*first character isn't an aphabet*/
	if(*data > 122 || *data < 65 || (*data > 90 && *data < 97))
	{
		if(*data != ' ' || *data != '\n' || *data == '\t')
		{
			wordCount--;
		}
	}

	return wordCount;
}

int LineCount(int *data, int totalChar)
{
	int i;
	int lineCount = 0;

	for(i = 0; i < totalChar; i++)
	{		
		if(data[i] == '\n')
		{
			lineCount++;
		}
	}
	return lineCount;
}

void Original(int *data, int totalChar)
{
	int i;

	printf("--original--\n");
	for(i = 0; i < totalChar; i++)
	{
		printf("%c", data[i]);		
	}	
}

void ToLowerCase(int *data, int *toLowerCount, int totalChar)
{
	int i;
	int count = 0;

	printf("--lower case--\n");
	for(i = 0; i < totalChar; i++)
	{
		if(data[i] >= 65 && data[i] <= 90)
		{
			data[i] = data[i] + 32;
			count++;
		}	
		*toLowerCount = count;
		printf("%c", data[i]);
	}
}


