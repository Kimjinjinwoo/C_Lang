#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
void IterativeMergeSort(int n, int arr[]);
element pop(nodePointer* front, nodePointer* rear);
void push(element data, nodePointer* front, nodePointer* rear);

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	fscanf(fr, "%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (int ii = 0; ii < n; ii++) {
		fscanf(fr, "%d", &arr[ii]);
	}
	//그냥 출력해보기
	IterativeMergeSort(n, arr);
	return 0;
}



void IterativeMergeSort(int n, int arr[]) {
	// queue 이니셜
	nodePointer rear = (nodePointer)malloc(sizeof(nodePointer));
	rear = NULL;
	nodePointer front = rear;
	for (int ii = 0; ii < n; ii++) {
		int* tmp_arr = (int*)malloc(sizeof(int));
		tmp_arr[0] = arr[ii];
		int tmp_len = 1;
		element tmp = { tmp_arr, tmp_len };
		push(tmp, &front, &rear);
	}



	while (1) {
		element A = pop(&front, &rear);
		if (front == NULL) {
			// 다 정렬된 상태~
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

		//push해야지~
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