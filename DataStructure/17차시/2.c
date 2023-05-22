#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define inf 1000000000

typedef struct element {
	int data;
	int u;
	int v;
}element;

element heap[1000];
int len = 0;

element ans[1000];
int ans_len = 0;

void prim(int n, int** adjacency);
void push(element item, int* n);
element pop(int* n);
void print(int n);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n;
	fscanf(fr, "%d", &n);
	int** adjacency = (int**) malloc(sizeof(int*) * n);
	for (int ii = 0; ii < n; ii++) {
		adjacency[ii] = (int*)malloc(sizeof(int) * n);
		for (int jj = 0; jj < n; jj++) {
			fscanf(fr, "%d", &adjacency[ii][jj]);
		}
	}
	prim(n, adjacency);
	print(n);
}

void prim(int n, int** adjacency) {
	int* visited = (int*)malloc(sizeof(int) * n);
	for (int ii = 0; ii < n; ii++) {
		visited[ii] = 0;
	}

	int start = 0;
	visited[start] = 1;
	for (int ii = 0; ii < n; ii++) {
		if (visited[ii] == 0) {
			element item = { adjacency[start][ii], start, ii };
			push(item, &len);
		}
	}


	while (1) {
		element now = pop(&len);
		if (visited[now.v] == 1)
			continue;

		ans[ans_len] = now;
		ans_len++;
		if (ans_len == n - 1) {
			break;
		}

		start = now.v;
		visited[start] = 1;
		for (int ii = 0; ii < n; ii++) {
			if (!visited[ii]) {
				element item = { adjacency[start][ii] , start, ii };
				push(item, &len);
			}
		}
	}

}

void print(int n) {
	FILE* fw = fopen("output.txt", "w");
	int total = 0;

	int** adjacency = (int**) malloc(sizeof(int*) * n);
	for (int ii = 0; ii < n; ii++) {
		adjacency[ii] = (int*)malloc(sizeof(int) * n);
		for (int jj = 0; jj < n; jj++) {
			adjacency[ii][jj] = 0;
		}
	}

	fprintf(fw, "Adjacency matrix representation MCST = { ");
	for (int ii = 0; ii < ans_len; ii++) {
		element item = ans[ii];
		fprintf(fw, "(%d, %d), ", item.u, item.v);
		adjacency[item.u][item.v] = item.data;
		adjacency[item.v][item.u] = item.data;
		total += item.data;
	}
	fprintf(fw, "}\n");
	fprintf(fw, "Total cost  = %d\n\n", total);

	for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < n; jj++) {
			fprintf(fw, "%d ", adjacency[ii][jj]);
		}
		fprintf(fw, "\n");
	}

}

void push(element item, int* n) {
	int i;
	i = ++(*n);
	while ((i != 1) && (item.data < heap[i / 2].data)) {
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
		if ((child < *n) && (heap[child].data > heap[child + 1].data))
			child++;
		if (temp.data <= heap[child].data)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}