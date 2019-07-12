#include "BST.h"

TreeNode *CreateTreeNode(char *word){
	TreeNode *newTreeNode = NULL;
	newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
	if(newTreeNode == NULL){
		printf("Create node error");
		return NULL;
	}
	else{
		if(word == NULL){
			return newTreeNode;
		}
		else{
			strcpy(newTreeNode->word, word);
			newTreeNode->counter = 1;
			newTreeNode->left = NULL;
			newTreeNode->right = NULL;
			return newTreeNode;
		}
	}
}

void InsertTreeNode(TreeNode *currentTreeNode, char *word){
	if(strcmp(word, currentTreeNode->word) > 0){
		if(currentTreeNode->right != NULL){
			InsertTreeNode(currentTreeNode->right, word);
		}
		else{
			currentTreeNode->right = CreateTreeNode(word);
			return;
		}
	}
	else if(strcmp(word, currentTreeNode->word) < 0){  
		if(currentTreeNode->left != NULL){
			InsertTreeNode(currentTreeNode->left, word);
		}
		else{
			currentTreeNode->left = CreateTreeNode(word);
			return;
		}
	}
	else if(strcmp(word, currentTreeNode->word) == 0){
		currentTreeNode->counter++;
		return;
	}
}

void DeleteTreeNode(TreeNode *currentTreeNode, char *word){
	if(currentTreeNode == NULL){
		return;
	}
	else if(strcmp(word, currentTreeNode->word) > 0){
		DeleteTreeNode(currentTreeNode->right, word);
	}
	else if(strcmp(word, currentTreeNode->word) < 0){
		DeleteTreeNode(currentTreeNode->left, word);
	}
	else if(strcmp(word, currentTreeNode->word) == 0){
		if(currentTreeNode->counter != 0){
			currentTreeNode->counter--;
		}
		return;
	}
}

TreeNode *SearchTreeNode(TreeNode *currentTreeNode, char *word){
	if(currentTreeNode == NULL){
		printf("%s Not Find!\n", word);
	}
	else if(strcmp(word, currentTreeNode->word) > 0){
		SearchTreeNode(currentTreeNode->right, word);
	}
	else if(strcmp(word, currentTreeNode->word) < 0){
		SearchTreeNode(currentTreeNode->left, word);
	}
	else if(strcmp(word, currentTreeNode->word) == 0){
		return currentTreeNode;
	}

	return NULL;
}


void InorderTraversal(TreeNode *currentTreeNode){
	if(currentTreeNode != NULL){
		InorderTraversal(currentTreeNode->left);
		if(currentTreeNode->counter > 0){
			printf("%-15s%d\n", currentTreeNode->word, currentTreeNode->counter);
		}
		InorderTraversal(currentTreeNode->right);
	}
}

