#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define inf 1000000

typedef struct {
	int data;
	int u;
	int v;
}element;

element heap[100];
int n = 0;
int matrix[100][100];
int roots[1000];

void push(element item, int* n);
element pop(int* n);
int union_find(int u);
void union_push(int u, int v);


int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int N; fscanf(fr, "%d", &N);
	for (int ii = 0; ii < N; ii++) {
		for (int jj = 0; jj < N; jj++) {
			fscanf(fr, "%d", &matrix[ii][jj]);
		}
	}

	for (int ii = 0; ii < N; ii++) {
		for (int jj = ii + 1; jj < N; jj++) {
			element point = { matrix[ii][jj], ii, jj };
			push(point, &n);
		}
	}

	int ans_len = 1;

	/*
	while (1) {
		element now = pop(&n);
		if (union_find(now.u) == union_find(now.v)) {
			continue;
		}
		ans_len++;
		if (ans_len == n - 1) break;
		printf("(%d, %d)\n", now.u, now.v);
	}*/

	while (n) {
		printf("%d ", pop(&n));
	}
}

void push(element item ,int* n) {
	int i = ++(*n);
	while ((i != 1) && (item.data < heap[i / 2].data)) {
		//printf("%d\n", i);
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
		if ((child < *n)&& (heap[child].data > heap[child + 1].data)){
			child++;
		}
		if (temp.data <= heap[child].data) break;

		heap[parent] = heap[child];
		parent = child;
		child = parent * 2;
	}
	heap[parent] = temp;
	return item;
}

int union_find(int u) {
	int now = u;
	int root = roots[u];
	while (roots[root] != root) {
		root = roots[root];
	}
	return root;
}

void union_push(int u, int v) {
	roots[union_find(u)] = union_find(v);
}
