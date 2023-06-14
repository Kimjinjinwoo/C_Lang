#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int n;
int* arr;
void SWAP(int, int);
void quickSort(int left, int right);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	fscanf(fr, "%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (int ii = 0; ii < n; ii++) {
		fscanf(fr, "%d", &arr[ii]);
		printf("%d ", arr[ii]);
	}
	printf("\n");


	quickSort( 0, n-1);

	for (int ii = 0; ii < n; ii++) {
		printf( "%d ", arr[ii]);
	}
}

void SWAP(int idx_a, int idx_b) {
	int temp = arr[idx_a];
	arr[idx_a] = arr[idx_b];
	arr[idx_b] = temp;
}

void quickSort( int left, int right) {
	int pivot, ii, jj;
	int temp;
	if (left < right) {
		ii = left; jj = right + 1;
		pivot = arr[left];
		do {
			do ii++; while (arr[ii] < pivot);
			do jj--; while (arr[jj] > pivot);
			if (ii < jj) SWAP(ii, jj);
		} while (ii < jj);
		SWAP(left, jj);
		quickSort(left, jj - 1);
		quickSort(jj + 1, right);
	}
}