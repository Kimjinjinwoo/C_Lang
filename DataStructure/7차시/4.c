#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct stack* stackPointer;
typedef struct stack {
	int data;
	stackPointer link;
};
void insert(stackPointer*, int);
int pop(stackPointer*, int*);

int main(void)
{
	FILE* fr = fopen("input.txt", "r");
	stackPointer top;
	top = (stackPointer)malloc(sizeof(*top));
	int data, num_data = 0;;
	while (feof(fr) == 0)
	{
		fscanf(fr, "%d", &data);
		insert(&top, data);
		num_data++;
	}
	fclose(fr);
	FILE* fw = fopen("output.txt", "w");
	while (num_data > 0) {
		fprintf(fw, "%d ", pop(&top, &num_data));
	}
	return 0;
}

void insert(stackPointer* top, int data) {
	stackPointer tmp;
	stackPointer x = *top;
	tmp = (stackPointer)malloc(sizeof(*tmp));
	tmp->data = data;
	tmp->link = (*top);
	* top = tmp;
}

int pop(stackPointer* top, int* num_data) {
	int data = (*top)->data;
	stackPointer tmp = (*top);
	(*top) = (*top)->link;
	*num_data = *num_data - 1;
	free(tmp);
	return data;
}