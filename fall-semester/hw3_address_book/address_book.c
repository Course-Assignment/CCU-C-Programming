#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE      1
#define FALSE     0
#define MAXLENGTH 1024
#define MAXRECORD 1000

typedef struct{
	char studentID[10];
	char name[20];
	char phone[15];
	int age;
}Data;

void Insert(Data *addressBook, Data temp, int *record);
void Update(Data *addressBook, Data temp, char *searchID, int record);
void Delete(Data *addressBook, char *searchID, int *record);
void Write(Data *addressBook, char *pattern, int record);
void Find(Data *addressBook, char *pattern, int record);
void Sort(Data *addressBook, char *pattern ,int record);
void List(Data *addressBook, int record);

void SplitToTemp(Data *temp, char *searchPattern, char *input, char function);
void SplitToPattern(char *input, char *searchPattern);
void PrintSuccessOutput(Data *addressBook, int index);

int compareStudentID(const void *a, const void *b);
int compareName(const void *a, const void *b);
int comparePhone(const void *a, const void *b);
int compareAge(const void *a, const void *b);

int main(void){

	int record = 0;
	char command = '\0';
	char *input = (char *)malloc(MAXLENGTH*sizeof(char));
	char *searchPattern = (char *)malloc(50*sizeof(char));
	Data addressBook[MAXRECORD];
	Data temp;

	while(TRUE){

		printf("Please input command(i/d/u/f/l/s/w/e) and data : ");
		input = fgets(input, MAXLENGTH, stdin);
		strncpy(&command, input, 1);
		switch(command){
			case 'i':
				SplitToTemp(&temp, searchPattern, input, 'i');
				Insert(addressBook, temp, &record);
				break;
			case 'd':
				SplitToPattern(input, searchPattern);
				Delete(addressBook, searchPattern, &record);
				break;
			case 'u':
				SplitToTemp(&temp, searchPattern, input, 'u');
				Update(addressBook, temp, searchPattern, record);
				break;
			case 'f':
				SplitToPattern(input, searchPattern);
				Find(addressBook, searchPattern, record);
				break;
			case 'l':
				List(addressBook, record);
				break;
			case 's':
				SplitToPattern(input, searchPattern);
				Sort(addressBook, searchPattern, record);
				break;
			case 'w':
				SplitToPattern(input, searchPattern);
				Write(addressBook, searchPattern, record);
				break;
			case 'q':
				printf("If you want to exit?(Y/N)? ");
				scanf("%c", &command);
				if(command == 'y' || command == 'Y'){
					free(input);
					free(searchPattern);
					return 0;
				}else{
					break;
				}
		}
	}
	return 0;
}

void SplitToTemp(Data *temp, char *searchPattern, char *input, char function){

	int counter = 1;
	char *currentToken = NULL;
	currentToken = strtok(input, ",");
	if(function == 'u'){
		currentToken = strtok(NULL, ",");
		strcpy(searchPattern, currentToken);
	}
	while(currentToken != NULL){
		currentToken = strtok(NULL, ",");
		if(counter == 1){
			strcpy(temp->studentID, currentToken);
			counter++;
		}
		else if(counter == 2){
			strcpy(temp->name, currentToken);
			counter++;
		}
		else if(counter == 3){
			strcpy(temp->phone, currentToken);	
			counter++;
		}
		else if(counter == 4){
			temp->age = atoi(currentToken);
			break;
		}
	}
}

void SplitToPattern(char *input, char *searchPattern){

	int counter = 0;
	char *currentToken = NULL;
	currentToken = strtok(input, ",");
	while(currentToken != NULL){
		currentToken = strtok(NULL, ",");
		counter++;
		if(counter == 1){
			strcpy(searchPattern, currentToken);
			searchPattern[strlen(searchPattern)-1] = '\0';
			break;
		}
	}
}

void Insert(Data *addressBook, Data temp, int *record){
	
	int i, outputCondition = TRUE;
	if(*record == 0){
		outputCondition = TRUE;	
	}
	else{
		for(i = 0; i< *record; i++){
			if(strcmp(addressBook[i].studentID, temp.studentID) == 0){
					outputCondition = FALSE;
					break;
			}
		}
	}

	if(outputCondition == TRUE){
		strcpy(addressBook[*record].studentID, temp.studentID);
		strcpy(addressBook[*record].name, temp.name);
		strcpy(addressBook[*record].phone, temp.phone);
		addressBook[*record].age = temp.age;
		PrintSuccessOutput(addressBook, *record);
		(*record)++;
	}
	else if(outputCondition == FALSE){
		printf("Insert error! studentID is exists!\n");
	}
}

void Delete(Data *addressBook, char *searchID, int *record){

	int i, index;
	int outputCondition = FALSE;
	for(i = 0; i < *record; i++){
		if(strcmp(addressBook[i].studentID, searchID) == 0){
			index = i;
			outputCondition = TRUE;
			break;
		}
	}
	if(outputCondition == TRUE){
		PrintSuccessOutput(addressBook, index);
		for(i = index; i+1 < *record; i++){
			strcpy(addressBook[i].studentID, addressBook[i+1].studentID);
			strcpy(addressBook[i].name, addressBook[i+1].name);
			strcpy(addressBook[i].phone, addressBook[i+1].phone);
			addressBook[i].age = addressBook[i+1].age;
		}
		(*record)--;
	}
	else{
		printf("Delete error! studentID not exists!\n");
	}

}

void Update(Data *addressBook, Data temp, char *searchID, int record){
	
	int i, index, outputCondition = FALSE;
	for(i = 0; i < record; i++){
		if(strcmp(addressBook[i].studentID, searchID) == 0){
			index = i;
			outputCondition = TRUE;
			break;
		}
	}
	for(i = 0; i < record; i++){
		if(strcmp(addressBook[i].studentID,temp.studentID) == 0){
			outputCondition = -1;
			printf("Update pattern has exist!\n");
		}
	}
	if(outputCondition == TRUE){
		strcpy(addressBook[index].studentID, temp.studentID);
		strcpy(addressBook[index].name, temp.name);
		strcpy(addressBook[index].phone, temp.phone);
		addressBook[index].age = temp.age;
		PrintSuccessOutput(addressBook, index);
	}
	else if(outputCondition == FALSE){
		printf("Update error! studentID not exists!\n");
	}
}
	
void Find(Data *addressBook, char *pattern, int record){
	
	int index = 0;
	int counter = 0;
	char *p_studentID = NULL;
	char *p_name = NULL;
	char *p_phone = NULL;
	while(index < record){
		p_studentID = strstr(addressBook[index].studentID, pattern);
		p_name = strstr(addressBook[index].name, pattern);
		p_phone = strstr(addressBook[index].phone, pattern);
		if(p_studentID != NULL || p_name != NULL || p_phone != NULL){
			PrintSuccessOutput(addressBook, index);
			counter++;
		}
		index++;
	}
	if(counter == 0){
		printf("Can't find pattern!\n");
	}
}

void List(Data *addressBook, int record){

	int i;
	for(i = 0; i < record; i++){
		PrintSuccessOutput(addressBook, i);
	}
}

void Sort(Data *addressBook, char *pattern ,int record){
	
	if(strcmp(pattern, "studentID") == 0){
		qsort(addressBook, record, sizeof(Data), compareStudentID);
		List(addressBook, record);
	}
	else if(strcmp(pattern, "name") == 0){
		qsort(addressBook, record, sizeof(Data), compareName);
		List(addressBook, record);
	}
	else if(strcmp(pattern, "phone") == 0){
		qsort(addressBook, record, sizeof(Data), comparePhone);
		List(addressBook, record);
	}
	else if(strcmp(pattern, "age") == 0){
		qsort(addressBook, record, sizeof(Data), compareAge);
		List(addressBook, record);
	}
	else{
		printf("Sort error! Input invalid pattern!\n");
	}
}

void Write(Data *addressBook, char *pattern, int record){

	FILE *fptr = NULL;
	int i;
	fptr = fopen(pattern, "w");
	if(fptr != NULL){
		for(i = 0; i < record; i++){
		fprintf(fptr, "%s,%s,%s,%d\n", addressBook[i].studentID, addressBook[i].name, addressBook[i].phone, addressBook[i].age);
		}
		fclose(fptr);
		printf("Writing file successful\n");
	}
	else{
		printf("Writing file failure\n");
	}
}

void PrintSuccessOutput(Data *addressBook, int index){
	printf("%s,%s,%s,%d\n", addressBook[index].studentID, addressBook[index].name, addressBook[index].phone, addressBook[index].age);
}

int compareStudentID(const void *a, const void *b){
	Data *A = (Data *)a;
	Data *B = (Data *)b;
	return strcmp(A->studentID,B->studentID);
}

int compareName(const void *a, const void *b){
	Data *A = (Data *)a;
	Data *B = (Data *)b;
	return strcmp(A->name,B->name);
}

int comparePhone(const void *a, const void *b){
	Data *A = (Data *)a;
	Data *B = (Data *)b;
	return strcmp(A->phone,B->phone);
}

int compareAge(const void *a, const void *b){
	Data *A = (Data *)a;
	Data *B = (Data *)b;
	return A->age - B->age;
}


