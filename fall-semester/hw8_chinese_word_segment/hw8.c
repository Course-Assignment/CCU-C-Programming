#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBYTE  64
#define MAXINDEX 33268
#define MAX_ARTICLE_CHAR 4096
#define UTF8_BYTE_SIZE 3
#define TRUE  1
#define FALSE 0

typedef struct dictionary{
	char word[MAXBYTE];
	struct dictionary *next;
}Dictionary;

void InsertDictionary(char *word, Dictionary **hashTable);
int main(int argc, char *argv[]){
	
	FILE *dictionaryPtr = NULL;
	FILE *articlePtr = NULL;
	char buffer[MAXBYTE];
	char article[MAX_ARTICLE_CHAR];
	int i;
	Dictionary **hashTable;
	hashTable = (Dictionary **)malloc(MAXINDEX*sizeof(Dictionary *));
	for(i = 0; i < MAXINDEX; i++){
		hashTable[i] = (Dictionary *)malloc(sizeof(Dictionary));
	}

	if(argc == 3){
		dictionaryPtr = fopen(argv[1], "r");
		articlePtr = fopen(argv[2], "r");
		while(fgets(buffer, MAXBYTE, dictionaryPtr) != NULL){
			InsertDictionary(buffer, hashTable);			
		}
		while(fgets(article, MAXBYTE, articlePtr) != NULL){

		}
	}
	else if(argc == 2){
		dictionaryPtr = fopen(argv[1], "r");
	}
	else{
		printf("Invalid Command\n");
		return 0;
	}
}

//dbj2 hash_function
int Hash(char *key){
	unsigned long long hash = 5381;
	int i = 0;
	while(key[i]){
		hash = ((hash << 5) + hash) + key[i];
		i++;
	}	
	return hash%MAXINDEX;
}

void InsertDictionary(char *word, Dictionary **hashTable){
	int index = Hash(word);
	while(hashTable[index] != NULL){
		if(strcmp(hashTable[index]->word, word) == 0){
			return;
		}
		hashTable[index] = hashTable[index]->next;
	}
	hashTable[index] = (Dictionary *)malloc(sizeof(Dictionary));
	strcpy(hashTable[index]->word, word);
	hashTable[index]->next = NULL;
	return;
}

int SearchDictionary(char *word, Dictionary **hashTable){
	int index = Hash(word);
	while(hashTable[index] != NULL){
		if(strcmp(hashTable[index]->word, word) == 0){
			return TRUE;
		}
		hashTable[index] = hashTable[index]->next;
	}
	return FALSE;
}

void WordSegmentation(char *word, Dictionary **hashTable){
	char *temp = word;
	while(*word != '\0'){
		int i, maxLength = 0;
		for(i = -1; i < maxLength; i++){
			if(SearchDictionary(word, hashTable) == TRUE){
				maxLength++;
			}
			else{
				
			}
		}
	}
}
