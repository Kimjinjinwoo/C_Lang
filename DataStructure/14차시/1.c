#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
} element;
element heap[100];
int n = 0;
void push(element item, int* n);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int N; fscanf(fr, "%d", &N);
	for (int ii = 0; ii < N; ii++) {
		int data; fscanf(fr,"%d", &data);
		element item = { data };
		push(item, &n);
	}
	for (int jj = 1; jj < n; jj++) {
		printf("%d ", heap[jj].key);
	}
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