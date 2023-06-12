#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void weightedUnion(int A, int B);

int* parent;

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n; fscanf(fr, "%d", &n);

	parent = malloc(sizeof(int) * (n+1));
	for (int ii = 0; ii < 13; ii++) {
		parent[ii] = -1;
	}

	for (int ii = 0; ii < n; ii++) {
		int A, B; fscanf(fr, "%d = %d,", &A, &B);
		weightedUnion(A, B);
	}
	for (int ii = 0; ii < 13; ii++) {
		printf("%d -> %d\n", ii, parent[ii]);
	}
}

void weightedUnion(int A, int B) {
	A = find(A); B = find(B);
	int tmp = parent[A] + parent[B];

	if (parent[A] > parent[B]) {
		parent[A] = B;
		parent[B] = tmp;
	}
	else {
		parent[B] = A;
		parent[A] = tmp;
	}
}

int find(int num) {
	if (parent[num] < 0)
		return num;
	return parent[num] = find(parent[num]);
}