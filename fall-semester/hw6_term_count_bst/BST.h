#ifndef  __BST_H__
#define __BST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1024	
#define MAXLINE 1024

typedef struct treeNode{
	char word[MAXCHAR];
	int counter;
	struct treeNode *left;
	struct treeNode *right;
}TreeNode;

TreeNode *CreateTreeNode(char *word);
void InsertTreeNode(TreeNode *currentNode, char *word);
void DeleteTreeNode(TreeNode *currentNode, char *word);
TreeNode *SearchTreeNode(TreeNode *currentNode, char *word);
void InorderTraversal(TreeNode *root);

#endif
