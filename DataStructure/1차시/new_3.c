#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int** Init_matrix(int);
int calculate(int**, int**, int, int, int);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n;
	fscanf(fr, "%d", &n);
	// get_A
	int** A = Init_matrix(n);
	for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < n; jj++) {
			fscanf(fr, "%d", &A[ii][jj]);
		}
	}
	//get_B
	int** B = Init_matrix(n);
	for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < n; jj++) {
			fscanf(fr, "%d", &B[ii][jj]);
		}
	}
	//get_C
	int** C = Init_matrix(n);
	for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < n; jj++) {
			C[ii][jj] = calculate(A, B, ii, jj, n);
		}
	}
	// print C
	FILE* fw = fopen("output.txt", "w");
	for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < n; jj++) {
			fprintf(fw, "%d", C[ii][jj]);
			if (jj != n - 1) {
				fprintf(fw, " ");
			}
		}
		if (ii != n - 1) {
			fprintf(fw, "\n");
		}
	}
	fclose(fw);
	fclose(fw);
}

int** Init_matrix(int n) {
	int** list = (int**)malloc(sizeof(int*) * n);
	for (int ii = 0; ii < n; ii++) {
		list[ii] = (int*)malloc(sizeof(int) * n);
	}
	return list;
}

int calculate(int** A, int** B, int row_idx, int col_idx, int n) {
	int sum = 0;
	for (int ii = 0; ii < n; ii++) {
		sum += A[row_idx][ii] * B[ii][col_idx];
	}
	return sum;
}