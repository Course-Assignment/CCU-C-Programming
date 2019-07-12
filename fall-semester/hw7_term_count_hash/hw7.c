#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

int main(){
	char buffer[MAXCHAR];
	char *function = NULL;
	char *word = NULL;
	char delimiter[] = "\t\n";
	int i;

	Data *find = NULL;
	Data **hashTable;
	hashTable = (Data **)malloc(MAXINDEX*sizeof(Data *));
	for(i=0; i < MAXINDEX-1; i++){
		hashTable[i] = (Data *)malloc(sizeof(Data));
	}

	while(fgets(buffer, MAXCHAR, stdin) != NULL){
		function = strtok(buffer, delimiter);
		word = strtok(NULL, delimiter);
		if(strcmp(function, "insert") == 0){
			Insert(word, hashTable);
		}
		else if(strcmp(function, "delete") == 0){
			Delete(word, hashTable);
		}
		else if(strcmp(function, "find") == 0){
			find = Search(word, hashTable);
			printf("----------------\n");
			if(find != NULL){
				printf("%-15s%d\n", find->key, find->value);
			}
			else{
				printf("Not found!\n");
			}
			printf("----------------\n");
		}
	}
	free(hashTable);
	return 0;
}

