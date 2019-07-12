#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1024

typedef struct node{
	char word[MAXCHAR];
	int counter;
	struct node *next;
}Node;

Node *CreateNode(void);
void InsertNode(Node *firstNode, char *pattern);
void DeleteNode(Node *currentNode, Node *previousNode);
void Search(Node *firstNode, char *pattern, char mode, int *records);
void PrintList(Node *arrayPtr, int records);
Node *Sort(Node *firstNode, int records);
int compareNode(const void *a, const void *b);

int main(int argc, char* argv[]){

	FILE *filePtr = NULL;
	char *buffer = (char *)malloc(MAXCHAR*sizeof(char));
	char mode = '\0';
	int records = 0;

	Node *firstNode;
	firstNode = CreateNode();
	firstNode->next = NULL;
	
	filePtr = fopen(argv[1], "r");
	if(filePtr == NULL){
		printf("File open failed\n");
		return 0;
	}
	
	if(fgets(buffer, MAXCHAR, filePtr) == NULL){
		printf("Term not exists!\n");
	}else{
		rewind(filePtr);
	}

	while(fgets(buffer, MAXCHAR, filePtr) != NULL){
		buffer[strlen(buffer)-1] = '\0';
		if(buffer[0] == '-'){
			mode = '-';
			Search(firstNode, buffer+1, mode, &records);
		}
		else{
			mode = '+';
			Search(firstNode, buffer, mode, &records);
		}
		mode = '\0';
	}
	
	firstNode = firstNode->next;
	PrintList(Sort(firstNode, records), records);
	return 0;
}

Node *CreateNode(void){
	Node *newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		printf("Node create fail");
		return NULL;
	}
	return newNode;
}

void InsertNode(Node *firstNode, char *pattern){
	Node *newNode = NULL;
	newNode = CreateNode();
	strcpy(newNode->word, pattern);
	newNode->counter = 1;

	newNode->next = firstNode->next;
	firstNode->next = newNode;
}

void DeleteNode(Node *currentNode, Node *previousNode){
	previousNode->next = currentNode->next;
	free(currentNode);
}

void PrintList(Node *arrayPtr, int records){
	int i;	
	for(i = 0; i < records; i++){
		printf("%s:%d\n", arrayPtr[i].word, arrayPtr[i].counter);
	}	
}

void Search(Node *firstNode, char *pattern, char mode, int *records){
	
	Node *currentNode = NULL;
	Node *previousNode = NULL;
	currentNode = CreateNode();
	previousNode = CreateNode();
	currentNode = firstNode;

	if(mode == '+'){
		while(currentNode != NULL){
			if(strcmp(currentNode->word, pattern) == 0){
				(currentNode->counter)++;
				return;
			}
			currentNode = currentNode->next;
		}
		InsertNode(firstNode, pattern);
		(*records)++;
		return;
	}
	else if(mode == '-'){
		while(currentNode != NULL){
			if(strcmp(currentNode->word, pattern) == 0){
				if(currentNode->counter == 1){
					DeleteNode(currentNode, previousNode);
					(*records)--;
					return;
				}
				else{
					currentNode->counter--;
					return;
				}
			}
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		return;
	}
}

Node *Sort(Node *firstNode, int records){
	Node *arrayPtr = NULL;
	arrayPtr = (Node *)malloc(records*sizeof(Node));
	int i = 0;
	while(firstNode != NULL){
		memcpy(arrayPtr+i, firstNode, sizeof(Node));
		firstNode = firstNode->next;
		i++;
	}
	qsort(arrayPtr, records, sizeof(Node), compareNode);
	return arrayPtr;
}

int compareNode(const void *a, const void *b){
	Node *A = (Node *)a;
	Node *B = (Node *)b;
	if(A->counter != B->counter){
		return B->counter - A->counter;
	}
	else{
		return strcmp(A->word, B->word);
	}
}
