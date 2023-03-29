#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};
void deletion(listPointer*, int);
void printChain(listPointer*, int);
void insert(listPointer*, int);



int main(void) {
	FILE* fr = fopen("input.txt", "r");
	listPointer first;
	first = (listPointer)malloc(sizeof(*first));
	int data, num_data = 0;
	while (feof(fr) == 0)
	{
		fscanf(fr, "%d",&data);
		insert(&first, num_data, data);
		num_data++;
	}
	fclose(fr);
	printf("chain: ");
	printChain(&first, num_data);

	printf("+----------------+\n");
	printf("\t1. insert\n");
	printf("\t2. delete\n");
	printf("\t3. length\n");
	printf("\t4. exit\n");
	printf("+----------------+\n\n");
	
	int command, idx;
	int conti = 1;
	while (conti)
	{
		printf("Menu: ");
		scanf("%d", &command);
		switch(command) {
		case 1: printf("insert: ");
			scanf("%d %d", &idx, &data);
			insert(&first, idx, data);
			num_data++;
			printf("result: ");
			printChain(&first, num_data);
			break;
		case 2:printf("delete: ");
			scanf("%d", &idx);
			deletion(&first, idx);
			num_data --;
			printf("result: ");
			printChain(&first, num_data);
			break;
		case 3:
			printf("length %d\n", num_data);
			break;
		case 4:
			printf("exit");
			conti = 0;
			break;
		}
		printf("\n");
	}
	return 0;
}

void deletion(listPointer* first, int idx)
{
	listPointer tmp;
	listPointer x = *first;
	tmp = (listPointer)malloc(sizeof(*tmp));
	if (idx != 0) {
		for (int ii = 1; ii < idx-1; ii++)
		{
			x = x->link;
		}
		tmp = x->link;
		x->link = tmp->link;
	}
	else {
		tmp = *first;
		*first = tmp->link;
	}
	free(tmp);
}

void printChain(listPointer* first, int num_data) {
	listPointer x = *first;
	for (int ii = 0; ii < num_data; ii++)
	{
		printf("%d ", x->data);
		x = x->link;
	}
	printf("\n");
}

void insert(listPointer* first, int idx,  int data) {
	listPointer tmp;
	listPointer x = *first;
	tmp = (listPointer) malloc( sizeof(*tmp) );
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

