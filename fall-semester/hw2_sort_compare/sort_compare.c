#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SWAP(x,y) {int t; t = x; x = y; y = t;}

double executiveTime(clock_t start, clock_t end);
double insertionSort(int *array, int arrayLength);
double selectionSort(int *array, int arrayLength);
double bubbleSort(int *array, int arrayLength);
double mergeSort(int *array, int arrayLength);
double quickSort(int *array, int arrayLength);
int compare(const void *a, const void *b);

int main()
{
	int counter, arrayLength;
	double timeArray[4][5];

	srand(clock()+time(NULL));
	
	for(arrayLength = 1000000; arrayLength > 100; arrayLength /= 10)
	{
		int *array = malloc(arrayLength*sizeof(int));
		for(counter = 0; counter < arrayLength; counter++)
		{
			array[counter] = rand();
		}		
		if(arrayLength == 1000)
		{
			timeArray[0][0] = insertionSort(array, arrayLength);
			timeArray[0][1] = selectionSort(array, arrayLength);
			timeArray[0][2] = bubbleSort(array, arrayLength);
			timeArray[0][3] = mergeSort(array, arrayLength);
			timeArray[0][4] = quickSort(array, arrayLength);
		}
		else if(arrayLength == 10000)
		{
			timeArray[1][0] = insertionSort(array, arrayLength);
			timeArray[1][1] = selectionSort(array, arrayLength);
			timeArray[1][2] = bubbleSort(array, arrayLength);
			timeArray[1][3] = mergeSort(array, arrayLength);
			timeArray[1][4] = quickSort(array, arrayLength);
		}
		else if(arrayLength == 100000)
		{
			timeArray[2][0] = insertionSort(array, arrayLength);
			timeArray[2][1] = selectionSort(array, arrayLength);
			timeArray[2][2] = bubbleSort(array, arrayLength);
			timeArray[2][3] = mergeSort(array, arrayLength);
			timeArray[2][4] = quickSort(array, arrayLength);
		}
		else if(arrayLength == 1000000)
		{ 
			timeArray[3][3] = mergeSort(array, arrayLength);
			timeArray[3][4] = quickSort(array, arrayLength);
		}
	}
	printf("--------------------------------------------------------------------\n");
	printf("|              | 1000       | 10000      | 100000     | 1000000    |\n");
	printf("--------------------------------------------------------------------\n");
	printf("|Insertion Sort| %-10lf | %-10lf | %-10lf |   X        |\n", timeArray[0][0], timeArray[1][0], timeArray[2][0]);
	printf("--------------------------------------------------------------------\n");
	printf("|Selection Sort| %-10lf | %-10lf | %-10lf |   X        |\n", timeArray[0][1], timeArray[1][1], timeArray[2][1]);
	printf("--------------------------------------------------------------------\n");
	printf("|Bubble    Sort| %-10lf | %-10lf | %-10lf |   X        |\n", timeArray[0][2], timeArray[1][2], timeArray[2][2]);
	printf("--------------------------------------------------------------------\n");
	printf("|Merge     Sort| %-10lf | %-10lf | %-10lf | %-10lf |\n", timeArray[0][3], timeArray[1][3], timeArray[2][3], timeArray[3][3]);
	printf("--------------------------------------------------------------------\n");
	printf("|Quick     Sort| %-10lf | %-10lf | %-10lf | %-10lf |\n", timeArray[0][4], timeArray[1][4], timeArray[2][4], timeArray[3][4]);
	printf("--------------------------------------------------------------------\n");

	return 0;
}

int compare(const void *a, const void *b)
{
	int c = *(int *)a;
	int d = *(int *)b;

	if(c > d)
	{
		return 1;
	}
	else if(c < d)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

double executiveTime(clock_t start, clock_t end)
{
	double time = 0.0;
	time = (double)(end-start)/CLOCKS_PER_SEC;
	return time;
}

double insertionSort(int *array, int arrayLength)
{
	int *arrayCopy = malloc(arrayLength*sizeof(int));
	int index, key, indexTemp, counter;
	double time;
	clock_t start, end;
	
	memcpy(arrayCopy, array, arrayLength*sizeof(int));

	start = clock();
	for(index = 1; index < arrayLength; index++)
	{
		indexTemp = arrayCopy[index];
		for(key = index-1; key >= 0 && arrayCopy[key] > indexTemp; key--)
		{
			arrayCopy[key+1] = arrayCopy[key];
		}
		arrayCopy[key+1] = indexTemp;
	}
	end = clock();

	if(arrayLength == 1000)
	{
		printf("Insertion Sort\n");
		printf("-------------------------------\n");
		printf("Before         After\n");
		for(counter = 0; counter < 99; counter++)
		{
			printf("%-15d%-d\n", array[counter], arrayCopy[counter]);
		}
		printf("\n");
	}
	
	time = executiveTime(start, end);
	return time;
}


double selectionSort(int *array, int arrayLength)
{
	int *arrayCopy = malloc(arrayLength*sizeof(int));
	int index, key, minValue, position, counter;
	double time;
	clock_t start, end;

	memcpy(arrayCopy, array, arrayLength*sizeof(int));

	start = clock();
	for(index = 0; index < arrayLength; index++)
	{
		position = index;
		minValue = arrayCopy[index];

		for(key = index+1; key < arrayLength; key++)
		{
			if(arrayCopy[key] < minValue)
			{
				position = key;
				minValue = arrayCopy[key];
			}
		}	
		SWAP(arrayCopy[index], arrayCopy[position]);
	}
	end = clock();

	if(arrayLength == 1000)
	{
		printf("Selection Sort\n");
		printf("-------------------------------\n");
		printf("Before         After\n");
		for(counter = 0; counter < 99; counter++)
		{
			printf("%-15d%-d\n", array[counter], arrayCopy[counter]);
		}
		printf("\n");
	}
	
	time = executiveTime(start, end);
	return time;
}

double bubbleSort(int *array, int arrayLength)
{
	int *arrayCopy = malloc(arrayLength*sizeof(int));
	int i, j, counter;
	double time;
	clock_t start, end;
	
	memcpy(arrayCopy, array, arrayLength*sizeof(int));

	start = clock();
	for(i = 0; i < arrayLength; i++)
	{
		for(j = 0; j < arrayLength-1-i; j++)
		{
			if(arrayCopy[j] > arrayCopy[j+1])
			{
				SWAP(arrayCopy[j], arrayCopy[j+1]);
			}
		}
	}
	end = clock();

	if(arrayLength == 1000)
	{
		printf("Bubble Sort\n");
		printf("-------------------------------\n");
		printf("Before         After\n");
		for(counter = 0; counter < 99; counter++)
		{
			printf("%-15d%-d\n", array[counter], arrayCopy[counter]);
		}
		printf("\n");
	}

	time = executiveTime(start, end);
	return time;
}

double mergeSort(int *array, int arrayLength)
{
	int *arrayCopy = malloc(arrayLength*sizeof(int));
	int counter;
	double time;
	clock_t start, end;

	memcpy(arrayCopy, array, arrayLength*sizeof(int));

	start = clock();
	qsort((void*)arrayCopy, arrayLength, sizeof(int), compare);
	end = clock();
	if(arrayLength == 1000)
	{
		printf("Merge Sort\n");
		printf("-------------------------------\n");
		printf("Before         After\n");
		for(counter = 0; counter < 99; counter++)
		{
			printf("%-15d%-d\n", array[counter], arrayCopy[counter]);
		}
		printf("\n");
	}

	time = executiveTime(start, end);
	return time;
}

double quickSort(int *array, int arrayLength)
{
	int *arrayCopy = malloc(arrayLength*sizeof(int));
	int counter;
	double time;
	clock_t start, end;

	memcpy(arrayCopy, array, arrayLength*sizeof(int));

	start = clock();
	qsort((void*)arrayCopy, arrayLength, sizeof(int), compare);
	end = clock();

	if(arrayLength == 1000)
	{
		printf("Quick Sort\n");
		printf("-------------------------------\n");
		printf("Before         After\n");
		for(counter = 0; counter < 99; counter++)
		{
			printf("%-15d%-d\n", array[counter], arrayCopy[counter]);
		}
		printf("\n");
	}

	time = executiveTime(start, end);
	return time;
}

