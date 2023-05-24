#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int* arr;
	int len;
}element;

int n;
int* arr;
element cut(element X, int i, int j);
element RecursiveMergeSort(element X);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	fscanf(fr, "%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (int ii = 0; ii < n; ii++) {
		fscanf(fr, "%d", &arr[ii]);
	}
	//그냥 출력해보기
	element X = { arr, n };
	X = RecursiveMergeSort(X);
	for (int ii = 0; ii < n; ii++) {
		printf("%d ", X.arr[ii]);
	}
	return 0;
}

element cut(element X, int i, int j) {
	// j > i;
	int* arrX = X.arr;
	int lenX = X.len;
	
	int len_cut = j - i + 1;
	int* arr_cut = (int*)malloc(sizeof(int) * len_cut);
	for (int ii = 0; ii < len_cut; ii++) {
		arr_cut[ii] = arrX[i + ii];
	}
	element out = { arr_cut, len_cut };
	return out;
}


element RecursiveMergeSort(element X) {
	int* arrX = X.arr;
	int lenX = X.len;
	if (lenX == 1) {
		return X;
	}
	
	int cut_idx = lenX / 2;
	element A = RecursiveMergeSort(cut(X, 0, cut_idx - 1));
	element B = RecursiveMergeSort(cut(X, cut_idx, lenX-1));

	int* arrA = A.arr, * arrB = B.arr;
	int lenA = A.len, lenB = B.len;

	int lenC = lenA + lenB;
	int* arrC = (int*)malloc(sizeof(int) * lenC);
	int idxA = 0, idxB = 0, idxC = 0;


	// 이제 진짜 소팅
	while ((idxA < lenA) && (idxB < lenB)) {
		int dataA = arrA[idxA];
		int dataB = arrB[idxB];
		if (dataA < dataB) {
			arrC[idxC] = arrA[idxA];
			idxC++; idxA++;
		}
		else {
			arrC[idxC] = arrB[idxB];
			idxC++; idxB++;
		}
	}
	while (idxB < lenB) {
		arrC[idxC] = arrB[idxB];
		idxC++; idxB++;
	}
	while (idxA < lenA) {
		arrC[idxC] = arrA[idxA];
		idxC++; idxA++;
	}

	element temp = { arrC, lenC };
	return temp;
}