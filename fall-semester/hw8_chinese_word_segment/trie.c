#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBYTE 8
#define MAXCHAR 768
#define UTF8_BYTE_SIZE 3
#define TRUE  1
#define FALSE 0

typedef struct trie{
	char word[MAXBYTE];
	struct trie *next;
	struct trie *child;
}Trie;

Trie *TrieCreate(char *word);
void TrieAdd(Trie **root, char *word);
int TrieSearch(Trie *root, char *word);
void WordSegmentation(Trie *root, char *word);

int main(int argc, char *argv[]){
	FILE *dictionaryPtr = NULL;
	FILE *articlePtr = NULL;
	char buffer[MAXCHAR];
	Trie *root = (Trie *)malloc(sizeof(Trie));
	if(argc == 3){
		dictionaryPtr = fopen(argv[1], "r");
		articlePtr = fopen(argv[2], "r");
		while(fgets(buffer, MAXCHAR, dictionaryPtr) != NULL){
			TrieAdd(&root, buffer);
		}
		while(fgets(buffer, MAXCHAR, articlePtr) != NULL){
			WordSegmentation(root, buffer);
		}
	}
	else if(argc == 2){
		dictionaryPtr = fopen(argv[1], "r");
		while(fgets(buffer, MAXCHAR, dictionaryPtr) != NULL){
			TrieAdd(&root, buffer);
		}
		while(fgets(buffer, MAXCHAR, stdin) != NULL){
			WordSegmentation(root, buffer);
		}
	}
	else{
		printf("Invalid Command!\n");
		return 0;
	}
	//fclose(dictionaryPtr);
	//fclose(articlePtr);
}

Trie *TrieCreate(char *word){
	Trie *node = NULL;
	node = (Trie *)malloc(sizeof(Trie));
	if(node != NULL){
		memcpy(node->word, word, UTF8_BYTE_SIZE);
		node->word[UTF8_BYTE_SIZE] = '\0';
		node->next = NULL;
		node->child = NULL;
		return node;
	}
	else{
		printf("Malloc Memmory Failed\n");
		return 0;
	}
}

void TrieAdd(Trie **root, char *word){
/*	while(*root != NULL){
		if(memcmp((*root)->word, word, UTF8_BYTE_SIZE) == 0){
			word += UTF8_BYTE_SIZE;
			*root = (*root)->child;
		}
		else{
			*root = (*root)->next;
		}
	}*/
	
	while((*root) != NULL){
		if(memcmp((*root)->word, word, UTF8_BYTE_SIZE) == 0){
			word += UTF8_BYTE_SIZE;
			*root = (*root)->child;
		}
		else{
			*root = (*root)->next;
		}
	} 

	unsigned char firstByte = *word;
	while(*word != 0){
		if(firstByte <= 127){
			word++;
		}
		else if(firstByte >= 239 && firstByte <= 247)
			(*root) = TrieCreate(word);
			printf("%s\n", word);
			word += UTF8_BYTE_SIZE;
			*root = (*root)->child;
		}
		firstByte = *word;
	}
	return;
}

int TrieSearch(Trie *root, char *word){
	int wordLength = 0;
	while(root != NULL){
		if(memcmp(root->word, word, UTF8_BYTE_SIZE) == 0){
			wordLength++;
			word += UTF8_BYTE_SIZE;
			root = root->child;
		}
		else{
			root = root->next;
		}
	}
	return wordLength;
}

void WordSegmentation(Trie *root, char *word){
	char segementWord[MAXCHAR];
	char temp[MAXCHAR];
	int condition = TRUE;
	int wordLength;
	while(*word != '\0'){
		wordLength = TrieSearch(root, word);
		if(wordLength > 0){
			if(condition == FALSE){			
				condition = TRUE;
				printf("%s\n", temp);
			}

			strncpy(segementWord, word, wordLength);
			segementWord[wordLength] = '\0';
			printf("%s\n", segementWord);

			word += wordLength;
		}
		else{
			condition = FALSE;
			if(temp[0] == '\0'){
				strncpy(temp, word, 1);
				temp[1] = '\0';
			}
			else{
				strncat(temp, word, 1);
			}
			word += 1;
		}
		wordLength = 0;
	}
}

