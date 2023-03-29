#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};
void concat(listPointer*, listPointer*, int, int);
void fprintChain(listPointer*, int);
void insert(listPointer*, int);


int main(void) {
	FILE* fr = fopen("input.txt", "r");
	listPointer list_first;
	list_first = (listPointer)malloc(sizeof(*list_first));
	listPointer list_second;
	list_second = (listPointer)malloc(sizeof(*list_first));
	int data, num_data_first = 1;
	char list1[100];
	fgets(list1, 100, fr);

	//num_data구하기...
	int idx = 0;
	while (1) {
		if (list1[idx] == ' ')
			num_data_first++;
		if (list1[idx] == '\n')
			break;
		idx++;
	}
	//printf("%d\n", num_data_first);
	
	int num_data_second = 1;
	char list2[100];
	fgets(list2, 100, fr);
	//num_data구하기...
	idx = 0;
	while (1) {
		if (list2[idx] == ' ')
			//printf("%d \n", idx);
			num_data_second++;
		if (list2[idx] == '\0')
			break;
		idx++;
	}
//	printf("%d\n", num_data_second);

	fclose(fr);
	FILE* fr2 = fopen("input.txt", "r");
	for (int ii = 0; ii < num_data_first; ii++)
	{
		fscanf(fr2, "%d", &data);
		insert(&list_first, ii, data);
	}

	//printChain(&list_first, num_data_first);
	
	for (int ii = 0; ii < num_data_second; ii++)
	{
		fscanf(fr2, "%d", &data);
		insert(&list_second, ii, data);
	}

	//printChain(&list_second, num_data_second);
	
	//합치기 
	concat(&list_first, &list_second, num_data_first, num_data_second);
	fprintChain(&list_first, num_data_first + num_data_second);
	
	return 0;
}


void concat(listPointer* first, listPointer* second, int num_data_first, int num_data_second) {
	listPointer x = *first;
	for (int ii = 0; ii < num_data_first - 1; ii++)
	{
		//printf("%d ", x->data);
		x = x->link;
	}
	x->link = *second;
}
void fprintChain(listPointer* first, int num_data) {
	FILE* fw = fopen("output.txt", "w");
	listPointer x = *first;
	for (int ii = 0; ii < num_data; ii++)
	{
		fprintf(fw, "%d ", x->data);
		x = x->link;
	}
	fclose(fw);
}

void insert(listPointer* first, int idx, int data) {
	listPointer tmp;
	listPointer x = *first;
	tmp = (listPointer)malloc(sizeof(*tmp));
	tmp->data = data;
	if (idx != 0) {
		for (int ii = 1; ii < idx; ii++)
		{
			x = x->link;
		}
		tmp->link = x->link;
		x->link = tmp;
	}
	else {
		tmp->link = NULL;
		*first = tmp;
	}
}

