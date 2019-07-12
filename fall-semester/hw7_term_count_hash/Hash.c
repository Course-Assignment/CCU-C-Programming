#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

#define MAXINDEX 30
#define	MAXCHAR 1024

int Hash(char *key){
	unsigned long long hash = 5381;
	int i = 0;
	while(key[i]){
		hash = ((hash << 5) + hash) + key[i];
		i++;
	}
	return hash%(MAXINDEX-1);
}

void Insert(char *key, Data **hashTable){
	int index = Hash(key);
	while(hashTable[index] != NULL){
		if(strcmp(hashTable[index]->key, key) == 0){
			hashTable[index]->value++;
			return;
		}
		hashTable[index] = hashTable[index]->next;
	}

	Data *item = (Data*)malloc(sizeof(Data));
	strcpy(item->key, key);
	item->value = 1;

	hashTable[index] = item;
}

void Delete(char *key, Data **hashTable){
	int index = Hash(key);
	while(hashTable[index] != NULL){
		if(strcmp(hashTable[index]->key, key) == 0){
			if(hashTable[index]->value >= 1){
				(hashTable[index]->value)--;
			}
			return;
		}
		hashTable[index] = hashTable[index]->next;
	}
}

Data *Search(char *key, Data **hashTable){
	int index = Hash(key);
	while(hashTable[index] != NULL){
		if(strcmp(hashTable[index]->key, key) == 0){
			return hashTable[index];
		}
		hashTable[index] = hashTable[index]->next;
	}
	return NULL;
}

