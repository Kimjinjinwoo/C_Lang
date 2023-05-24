#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define inf 1000000; 

typedef struct element {
	int* arr;
	int len;
}element;

typedef struct node* nodePointer;
typedef struct node {
	element data;
	nodePointer link;
};


int n;
int* arr;
void SWAP(int idx_a, int idx_b);
element cut(element X, int i, int j);
void naturalMergeSort(int n, int arr[]);
element pop(nodePointer* front, nodePointer* rear);
void push(element data, nodePointer* front, nodePointer* rear);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	fscanf(fr, "%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (int ii = 0; ii < n; ii++) {
		fscanf(fr, "%d", &arr[ii]);
	}
	//�׳� ����غ���
	naturalMergeSort(n, arr);
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


void naturalMergeSort(int n, int arr[]) {
	// queue �̴ϼ�
	nodePointer rear = (nodePointer)malloc(sizeof(nodePointer));
	rear = NULL;
	nodePointer front = rear;
	// ���⸸ ��� cut���� �� �ϸ� �ɰ� ������? ���~
	element X = { arr, n };
	int start = 0, data = arr[0];

	for (int ii = 1; ii < n; ii++) {
		int n_data = arr[ii];
		if (data > n_data) {
			// �߶� �־��ֱ�
			push(cut(X, start, ii-1), &front, &rear);
			start = ii;
			data = n_data;
		}
		else {
			data = n_data;

		}
	}// ������ ������ �� ó�� �� ���
	push(cut(X, start, n-1), &front, &rear);


	while (1) {
		element A = pop(&front, &rear);
		if (front == NULL) {
			// �� ���ĵ� ����~
			for (int ii = 0; ii < n; ii++) {
				printf("%d  ", A.arr[ii]);
			}
			break;
		}
		element B = pop(&front, &rear);
		int* arrA = A.arr, * arrB = B.arr;
		int lenA = A.len, lenB = B.len;

		int lenC = lenA + lenB;
		int* arrC = (int*)malloc(sizeof(int) * lenC);
		int idxA = 0, idxB = 0, idxC = 0;


		// ���� ��¥ ����
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

		//push�ؾ���~
		element temp = { arrC, lenC };
		push(temp, &front, &rear);
	}
}

element pop(nodePointer* front, nodePointer* rear) {
	element data = (*front)->data;
	(*front) = (*front)->link;

	return data;
}

void push(element data, nodePointer* front, nodePointer* rear) {
	nodePointer new_node = (nodePointer)malloc(sizeof(nodePointer));
	new_node->data = data;
	new_node->link = NULL;
	if ((*front) != NULL)
		(*rear)->link = new_node;
	(*rear) = new_node;

	if ((*front) == NULL) {
		(*front) = (*rear);
	}
}