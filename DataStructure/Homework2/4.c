#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AddQ(int, int*, int*, int*);
void DeleteQ(int*, int*, int*);
void List(int*, int, int);
int IsFull(int, int);
int IsEmpty(int, int);


int main(void) {
	int key;
	int queue[5];
	int front = -1, rear = -1;
	int cont = 1;
	while (cont) {
		printf("****************************************\n\
* 1. AddQ *\n\
*2. DeleteQ *\n\
*3. List *\n\
*4. Exit *\n\
****************************************\n");
		printf("Menu : ");
		scanf("%d", &key);
		switch (key) {
		case 1:
			printf("AddQ Data : ");
			int data;
			scanf("%d", &data);
			AddQ(data, queue, &front, &rear);
			break;

		case 2:
			DeleteQ(queue, &front, &rear);
			break;

		case 3:
			List(queue, front, rear);
			break;

		case 4:
			cont = 0;
			break;
		}

		printf("\n\n");
	}
}

void AddQ(int data, int* queue, int* front, int* rear) {
	*rear = (*rear + 1) % 5;
	queue[*rear] = data;
}

void DeleteQ(int* queue, int* front, int* rear) {
	int data = *front;
	if (*rear == *front)
	{
		printf("Error!\n");
		return;
	}
	*front = (*front + 1) % 5;
	printf("DeleteQ Data : %d\n", queue[*front]);
}

void List(int* queue, int front, int rear) {
	if (front == rear) {
		printf("\n");
		return;
	}
	printf("List :");
	while (front != rear) {
		front = (front + 1) % 5;
		printf(" %d", queue[front]);
	}
}

int IsEmpty(int front, int rear) {
	if (front == rear)
		return 1;
	else
		return 0;
}

int IsFull(int front, int rear) {
	if (front == rear)
		return 1;
	else
		return 0;
}
