#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
	int key;
} element;

void push(element item, int* n);
element pop(int* n);

element heap[MAX_ELEMENTS];
int n = 0;

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int N; fscanf(fr, "%d", &N);

	int data; fscanf(fr, "%d", &data);
	element X = { data };
	push(X, &n);
	for (int ii = 1; ii < N; ii++) {
		fscanf(fr, "%d", &data);
		element X = { data };
		push(X, &n);
	}

	for (int ii = 1; ii < n; ii++) {
		printf("%d ", heap[ii].key);
	}

	printf("\n");
	while (n) {
		printf("%d ", pop(&n));
	}
}

void push(element item, int* n) {
	int i;
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

element pop(int* n) {
	int parent, child;
	element item, temp;
	item = heap[1];

	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
		{
			child++;
		}
		if (temp.key >= heap[child].key) break;

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}