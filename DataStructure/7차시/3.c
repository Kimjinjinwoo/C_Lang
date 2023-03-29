#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};
void reverse(listPointer*, int);
void fprintChain(listPointer*, int);
void insert(listPointer*, int);



int main(void) {
	FILE* fr = fopen("input.txt", "r");
	listPointer first;
	first = (listPointer)malloc(sizeof(*first));
	int data, num_data = 0;
	while (feof(fr) == 0)
	{
		fscanf(fr, "%d", &data);
		insert(&first, num_data, data);
		num_data++;
	}
	fclose(fr);
	reverse(&first, num_data);
	
	return 0;
}

void reverse(listPointer* first, int num_data)
{
	listPointer reversed;
	listPointer x = *first;
	reversed = (listPointer)malloc(sizeof(*reversed));
	listPointer tmp;
	reversed = (listPointer)malloc(sizeof(*reversed));
	listPointer y = reversed;

	for (int ii = 0; ii < num_data; ii++)
	{
		x = *first;
		for (int jj = 1; jj < num_data - ii ; jj++)
		{
				x = x->link;
		}// 원래 Chain의 num_data-ii번째 노드에 도착
		insert(&reversed, ii, x->data);
	}
	fprintChain(&reversed, num_data);
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

