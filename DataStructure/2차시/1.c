#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int** make2dArray(int rows, int cols);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n, m;
	fscanf(fr, "%d %d", &n, &m);
	int** A = make2dArray(n, m);
	int** B = make2dArray(n, m);
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++) 
		{
			fscanf(fr, "%d", &A[i][j]);
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++)
		{
			fscanf(fr, "%d", & B[i][j]);
		}
	}
	fclose(fr);
	output(n, m, A, B);
}

void output(int n, int m, int** A, int** B)
{
	int** C = make2dArray(n, m);
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	FILE* fw = fopen("output.txt", "w");
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++)
		{
			fprintf(fw, "%d ", C[i][j]);
		}
		fprintf(fw, "\n");
	}
	fclose(fw);
}

int** make2dArray(int rows, int cols)
{
	int** x, i;

	x = (int**) malloc(rows * sizeof(int*));

	for (i = 0;i < rows;i++)
		x[i] = (int*) malloc( cols * sizeof(int));
	return x;
}