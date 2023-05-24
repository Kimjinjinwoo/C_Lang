#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int n;
int* arr;
void SWAP(int idx_a, int idx_b);
void quickSort(int arr[], int left, int right);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	fscanf(fr, "%d", &n);
	arr = (int*) malloc(sizeof(int) * n);

	for (int ii = 0; ii < n; ii++) {
		fscanf(fr, "%d", &arr[ii]);
	}
	//그냥 출력해보기
	quickSort(arr, 0, n-1);
	for (int ii = 0; ii < n; ii++) {
		printf("%d  ", arr[ii]);
	}
	return 0;
}

void SWAP(int idx_a, int idx_b) {
	int temp = arr[idx_a];
	arr[idx_a] = arr[idx_b];
	arr[idx_b] = temp;
}

void quickSort(int arr[], int left, int right) {
	int pivot, i, j;
	int temp;
	if (left < right) {
		i = left; j = right + 1;
		pivot = arr[left];
		do{
			do i++; while (arr[i] < pivot);
			do j--; while (arr[j] > pivot);
			if (i < j) SWAP(i, j);
		} while (i < j);
		SWAP(left, j);
		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	}
}