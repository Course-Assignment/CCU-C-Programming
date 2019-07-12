#ifndef  __HASH_H__
#define __HASH_H__

#define MAXINDEX 30
#define MAXCHAR 1024

typedef struct data{
	char key[MAXCHAR];
	int value;
	struct data *next;
}Data;

int Hash(char *key);
void Insert(char*, Data**);
void Delete(char*, Data**);
Data *Search(char*, Data**);

#endif

