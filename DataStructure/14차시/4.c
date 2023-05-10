#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
} element;
element heap[100];
int n = 0;
void push(element item, int* n);
element pop(int* n);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int N; fscanf(fr, "%d", &N);
	for (int ii = 0; ii < N; ii++) {
		int data; fscanf(fr, "%d", &data);
		element item = { -1 * data };
		push(item, &n);
	}
	printf("max heap : ");
	for (int jj = 1; jj <= N; jj++) {
		printf("%d ", -1 * heap[jj].key);
	}
	printf("\n");

	printf("sorted : ");
	for (int jj = 1; jj <= N; jj++) {
		printf("%d ", -1 * pop(&n).key);
	}
	printf("\n");

	fclose(fr);
	return 0;
}

void push(element item, int* n) {
	int i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

element pop(int* n) {
	int parent, child;
	element item, temp;
	// highest value
	item = heap[1];
	// use last element in heap to adjust heap
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n) {
		// find the larger child of the current parend
		if ((child < *n) && (heap[child].key < heap[child + 1].key)) {
			child++;
		}
		if (temp.key >= heap[child].key) {
			break;
		}
		// move to the next lower level
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}