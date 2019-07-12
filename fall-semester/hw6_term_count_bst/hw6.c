#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

typedef struct data{
	char word[MAXCHAR];
	int counter;
}Data;

void Count(TreeNode *root);
void CopyTree(TreeNode *root, Data *arr, int *counter);
int Compare(const void *a, const void *b);

int main(void){
		
	char buffer[MAXCHAR];
	char *function = NULL;
	char *word = NULL;
	char delimiter[] = "\t\n";
	TreeNode *root = CreateTreeNode(NULL);
	
	while(fgets(buffer, MAXCHAR, stdin) != NULL){
		function = strtok(buffer, delimiter);
		if(strcmp(function, "insert") == 0){
			word = strtok(NULL, delimiter);
			InsertTreeNode(root, word);
		}
		else if(strcmp(function, "delete") == 0){
			word = strtok(NULL, delimiter);
			DeleteTreeNode(root, word);
		}
		else if(strcmp(function, "find") == 0){
			word = strtok(NULL, delimiter);
			TreeNode *temp = SearchTreeNode(root, word);
			if(temp->counter == 0){
				printf("The Number of %s is Zero\n", word);
			}
			else{
				printf("----------------\n");
				printf("%-15s%d\n", word, temp->counter);
				printf("----------------\n");
			}
		}
		else if(strcmp(buffer, "inorder") == 0){
			printf("----------------\n");
			InorderTraversal(root);
			printf("----------------\n");
		}
		else if(strcmp(buffer, "count") == 0){
			printf("----------------\n");
			Count(root);
			printf("----------------\n");
		}
		else{
			printf("Input Invalid Arguments\n");
		}	
	}
	free(root);
	return 0;
}


void Count(TreeNode *root){
	Data *arr = (Data *)malloc(MAXLINE*sizeof(Data));
	int tempCounter = 0;
	int i;
	CopyTree(root, arr, &tempCounter);
	qsort(arr, tempCounter, sizeof(Data), Compare);
	for(i=0; i < tempCounter; i++){
		printf("%-15s%d\n", arr[i].word, arr[i].counter);
	}
	free(arr);
}

void CopyTree(TreeNode *root, Data *arr, int *counter){
	if(root != NULL){
		CopyTree(root->left, arr, counter);
		if(root->counter > 0){
			strcpy(arr[*counter].word, root->word);
			arr[*counter].counter = root->counter;
			(*counter)++;
		}
		CopyTree(root->right, arr, counter);
	}
}

int Compare(const void *a, const void *b){
	Data *A = (Data *)a;
	Data *B = (Data *)b;
	if(A->counter != B->counter){
		return B->counter - A->counter;
	}
	else{
		return strcmp(A->word, B->word);
	}
}

