#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void dfs(int now, int n, int** Adjacency, int** visited, int*** result);
void connect(int a, int b, int*** result);
void my_print(int n, int** result);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n;
	fscanf(fr, "%d", &n);

	// Adjacency¶û visited, result ÃÊ±âÈ­
	int** Adjacency = malloc(sizeof(int*)*n);
	int** result = malloc(sizeof(int*) * n);
	int* visited = malloc(sizeof(int) * n);
	for (int ii = 0; ii < n; ii++) {
		visited[ii] = 0;
		Adjacency[ii] = malloc(sizeof(int) * n);
		result[ii] = malloc(sizeof(int) * n);
		for (int jj = 0; jj < n; jj++) {
			fscanf(fr, "%d", &Adjacency[ii][jj]);
			result[ii][jj] = 0;
		}
	}

	dfs(0, n, Adjacency, &visited, &result);
	my_print(n, result);

	return 0;
}

void dfs(int now,int n, int** Adjacency, int** visited, int*** result) {
	(*visited)[now] = 1;
	for (int ii = 0; ii < n; ii++) {
		if ((*visited)[ii] == 0 && Adjacency[now][ii] == 1) {
			(*visited)[ii] = 1;
			connect(now, ii, result);
			dfs(ii, n, Adjacency, visited, result);
			return;
		}
	}
}

void connect(int a, int b, int*** result) {
	(*result)[a][b] = 1;
	(*result)[b][a] = 1;
	return;
}

void my_print(int n, int** result) {
	FILE* fw = fopen("output.txt", "w");
	fprintf(fw, "adjacency matrix (%d by %d), Tree Edges = { ", n, n);
	for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < ii; jj++) {
			if (result[ii][jj] == 1) {
				fprintf(fw, " (%d, %d),",jj ,ii);
			}
		}
	}
	fprintf(fw, " }\n");

	for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < n; jj++) {
			fprintf(fw, "%d ", result[ii][jj]);
		}
		fprintf(fw, "\n");
	}
}