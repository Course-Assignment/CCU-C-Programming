#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define for using strcasestr()
#define _GNU_SOURCE

#define MAXCHAR 1000
#define ON  1
#define OFF 0

char *strcasestr(const char *hastack, const char *needle);
char *StringSearch(char *string, char *find, int I_Mode);
void StringSubstitute(char *initialString, char *sourceWord, char *targetWord, int I_Mode, int A_Mode);

int main(int argc, char *argv[])
{
	char initialString[MAXCHAR];
	char *sourceWord = argv[argc-2];
	char *targetWord = argv[argc-1];
	
	int argcCounter;
	int I_Mode = OFF;
	int A_Mode = OFF;
	
	//Input arguments exception handling
	if(argc < 3)
	{
		printf("Input Too Few Arguments\n");
		return 0;
	}

	for(argcCounter = 0; argcCounter < argc-3; argcCounter++)
	{
		if(argv[argcCounter+1][0] == '-')
		{
			if(argv[argcCounter+1][1] == 'i' || argv[argcCounter+1][1] == 'a')
			{
				//Executing mode judge by input arguments
				switch(argv[argcCounter+1][1])
				{
					case 'i':
						if(I_Mode == OFF)
						{
							I_Mode = ON;
							break;
						}
						else
						{
							printf("Input Same Argument\n");
							return 0;
						}
					case 'a':
						if(A_Mode == OFF)
						{
							A_Mode = ON;
							break;
						}
						else
						{
							printf("Input Same Argument\n");
							return 0;
						}
				}
			}
			else
			{
				printf("Invalid Command\n");
				return 0;
			}
		}
		else
		{
			printf("Invalid Command\n");
			return 0;
		}
	}
	
	while(fgets(initialString, MAXCHAR, stdin) != NULL)
	{         
		StringSubstitute(initialString, sourceWord, targetWord, I_Mode, A_Mode);
	}
	
	return 0;
}

void StringSubstitute(char *initialString, char *sourceWord, char *targetWord, int I_Mode, int A_Mode)
{
	char resultString[MAXCHAR*2];
	strcpy(resultString, initialString);

	int resultStringLength = 0;
	int sourceWordLength = strlen(sourceWord);
	int targetWordLength = strlen(targetWord);

	char *positionPtr  = initialString; //Point to the character where the string hasn't been found
	char *sourceWordPtr = NULL;			//Point to the position where the source word be found

	sourceWordPtr = StringSearch(positionPtr, sourceWord, I_Mode);
		
	while(sourceWordPtr != NULL)
	{
		resultStringLength += (sourceWordPtr - positionPtr);
		resultString[resultStringLength] = '\0';

		strcat(resultString, targetWord);
		resultStringLength += targetWordLength;
		
		positionPtr = sourceWordPtr+sourceWordLength;
		strcat(resultString, positionPtr);
		
		if(A_Mode == OFF)
		{
			break;
		}

		sourceWordPtr = StringSearch(positionPtr, sourceWord, I_Mode);
	}

	printf("%s",resultString);
}

char *StringSearch(char *string, char *find, int I_Mode)
{
	char *sourceWordPtr = NULL;

	if(I_Mode == OFF)
	{
		sourceWordPtr = strstr(string, find);		
	}
	else if(I_Mode == ON)
	{
		sourceWordPtr = strcasestr(string, find);
	}

	return sourceWordPtr;
}
