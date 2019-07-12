#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void AllocateDynamicalArray(FILE *fptr, char ***data, int *maxLine, int *lineMaxChar);
void WriteFileInArray(FILE *fptr, char **data, int lineMaxChar);
void FreeAllocate(char ***data, int maxLine);

int FindStringDigitValue(char **data, int lineMaxChar, int counter);
void SortNormalMode(char **data, int maxLine);
void SortReverseMode(char **data, int maxLine);
void SortAtoiMode(char **data, int maxLine, int lineMaxChar);

int main(int argc, char *argv[])
{
	FILE *fptr = NULL;
	char **data = NULL;
	int lineMaxChar = 0, maxLine = 0;

	if(argc == 2)
	{
		fptr = fopen(argv[1], "r");
		if(fptr)
		{
			AllocateDynamicalArray(fptr, &data, &maxLine, &lineMaxChar);
			WriteFileInArray(fptr, data, lineMaxChar);		
			SortNormalMode(data, maxLine);
			FreeAllocate(&data, maxLine);
		}
		else
		{
			printf("File open fail\n");		
		}
	}
	else if(argc == 3)
	{
		if(strcmp(argv[1], "-n") == 0)
		{
			fptr = fopen(argv[2], "r");
			if(fptr)
			{
				AllocateDynamicalArray(fptr, &data, &maxLine, &lineMaxChar);
				WriteFileInArray(fptr, data, lineMaxChar);
				SortAtoiMode(data, maxLine, lineMaxChar);
				FreeAllocate(&data, maxLine);
			}
			else
			{
				printf("File open fail\n");		
			}
		}
		else if(strcmp(argv[1], "-r") == 0)
		{
			fptr = fopen(argv[2], "r");
			if(fptr)
			{
				AllocateDynamicalArray(fptr, &data, &maxLine, &lineMaxChar);
				WriteFileInArray(fptr, data, lineMaxChar);
				SortReverseMode(data, maxLine);
				FreeAllocate(&data, maxLine);
			}
			else
			{
				printf("File open fail\n");		
			}
		}
		else
		{
			printf("Command not found\n");				
		}
	}
	else
	{
		printf("Command not found\n");		
	}
	return 0;
}

void AllocateDynamicalArray(FILE *fptr, char ***data, int *maxLine, int *lineMaxChar)
{
	int ch, i, count = 0;
	while((ch = fgetc(fptr)) != EOF)
	{
		count++;
		if(ch == '\n')
		{
			(*maxLine)++;		
			if(count > *lineMaxChar)
			{
				*lineMaxChar = count;
			}	
			count = 0;
		}	
	}
	
	*data = calloc(*maxLine,sizeof(char *));
	for(i = 0; i < *maxLine; i++)
	{
		(*data)[i] = calloc(*lineMaxChar,sizeof(char));		
	}
}

void WriteFileInArray(FILE *fptr, char **data, int lineMaxChar)
{
	int i;
	rewind(fptr);	
	while(fgets(data[i++], lineMaxChar+1, fptr) != NULL);
}

void FreeAllocate(char ***data, int maxLine)
{
	int i;
	for(i = 0; i < maxLine; i++)
	{
		free((*data)[i]);
	}
	free(*data);
}

int FindStringDigitValue(char **data, int lineMaxChar, int counter)
{
	int i, digitValue = 0;
	for(i = 0; i < lineMaxChar; i++)
	{
		if(atoi(&data[counter][i]) != 0)
		{
			digitValue = atoi(&data[counter][i]);
			break;
		}
	}
	return digitValue;
}

void SortNormalMode(char **data, int maxLine)
{	
	int i, j;
	char *buffer = NULL;
	
	for(j = 0; j < maxLine-1; j++)
	{
		for(i = 0; i < maxLine-1-j; i++)
		{		
			if(strcmp(data[i], data[i+1]) > 0)
			{				
				buffer = data[i];
				data[i] = data[i+1];
				data[i+1] = buffer;
			}
		}
	}

	for(i = 0; i < maxLine; i++)
	{
		printf("%s", data[i]);		
	}
}

void SortAtoiMode(char **data, int maxLine, int lineMaxChar)
{	
	int i, j;
	char *buffer = NULL;
	int digitValue_1 ,digitValue_2;
	
	for(j = 0; j < maxLine-1; j++)
	{
		for(i =0; i < maxLine-1-j; i++)
		{
			digitValue_1 = FindStringDigitValue(data, lineMaxChar, i);
			digitValue_2 = FindStringDigitValue(data, lineMaxChar, i+1);

			if(digitValue_1 > digitValue_2)
			{
				buffer = data[i];
				data[i] = data[i+1];							
				data[i+1] = buffer;
			}
		}
	}
	
	for(i = 0; i < maxLine; i++)
	{
		printf("%s", data[i]);
	}
}

void SortReverseMode(char **data, int maxLine)
{
	int i, j;
	char *buffer = NULL;
	
	for(j = 0; j < maxLine-1; j++)
	{
		for(i = 0; i < maxLine-1-j; i++)
		{	
			if(strcmp(data[i], data[i+1]) < 0)
			{
				buffer = data[i];
				data[i] = data[i+1];							
				data[i+1] = buffer;
			}
		}
	}
	
	for(i = 0; i < maxLine; i++)
	{
		printf("%s", data[i]);		
	}		
}
