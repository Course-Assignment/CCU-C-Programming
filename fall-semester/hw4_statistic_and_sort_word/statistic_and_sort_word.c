#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0
#define MAXWORD 128
#define MAXLINE 1024

typedef struct{
	char word[MAXWORD];
	int counter;
}Data;

Data *Statistic(char **strArray, int strCount, int *records);
void Sort(Data *library, int *records);
int compare(const void *a, const void *b);

int main(void){
	
		Data *library;
		int i;
		int records = 0;
		int strCount = 0;
		char *buffer = (char *)malloc(MAXWORD*sizeof(char));
		char **strArray; 
		strArray = (char **)malloc(MAXLINE*sizeof(char *));
		for(i = 0; i < MAXLINE; i++){
			strArray[i] = (char *)malloc(MAXWORD*sizeof(char));
		}

		while(fgets(buffer, MAXLINE, stdin) != NULL){
			strcpy(strArray[strCount],buffer);							
			strArray[strCount][strlen(strArray[strCount])-1] = '\0';	
			strCount++;
		}
		library = Statistic(strArray, strCount, &records);
		Sort(library, &records);
		for(i = 0; i < records; i++){
			printf("%d %s\n", library[i].counter, library[i].word);
		}
		return 0;
}

Data *Statistic(char **strArray, int strCount, int *records){

		Data *library = (Data *)malloc(MAXLINE*sizeof(Data));
		int index, j;
		int condition = FALSE;

		for(index = 0; index < strCount; index++){
			for(j = 0; j < *records; j++){
				if(strcmp(library[j].word, strArray[index]) == 0){
					library[j].counter++;	
					condition = TRUE;
					break;
				}
				else{
					condition = FALSE;
				}
			}
			if(condition == FALSE){
				strcpy(library[*records].word, strArray[index]);
				library[*records].counter = 1;
				(*records)++;
			}
		}
		return library;
}

void Sort(Data *library, int *records){
	qsort(library, *records, sizeof(Data), compare);
}

int compare(const void *a, const void *b){
		
		Data *A = (Data *)a;
		Data *B = (Data *)b;
		if(A->counter != B->counter){
			return B->counter - A->counter;
		}
		else{
			return strcmp(A->word, B->word);
		}
}

