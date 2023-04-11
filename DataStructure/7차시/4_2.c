#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
};
void push(int, nodePointer*);

int main() {
	FILE* fr = fopen("input.txt", "r");
	int data;
	nodePointer top = NULL;
	
	while (!feof(fr)) {
		fscanf(fr, "%d", &data);
		push(data, &top);
		//printf("%d\n", data);
	}
	FILE* fw = fopen("ouput.txt", "w");
	while (top != NULL) {
		fprintf(fw, "%d ", pop(&top));
	}
}

int pop(nodePointer* top) {
	int data = (*top)->data;
	(*top) = (*top)->link;
	return data;
}

void push(int data, nodePointer* top) {
	if (*top == NULL) {
		(*top)= (nodePointer)malloc(sizeof(nodePointer));
		(*top)->data = data; (*top)->link = NULL;
	}
	else {
		nodePointer tmp = (nodePointer)malloc(sizeof(nodePointer));
		tmp->data = data; tmp->link = (*top);
		(*top) = tmp;
	}
}