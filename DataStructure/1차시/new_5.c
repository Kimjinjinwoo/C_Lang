#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int find(int* , int , int , int );

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n, m;
	fscanf(fr, "%d %d", &n, &m);
	int* list = (int*)malloc(sizeof(int) * n);

	for (int ii = 0; ii < n; ii++)
		fscanf(fr, "%d", &list[ii]);

	// find!!
	FILE* fw = fopen("output.txt", "w");
	fprintf(fw, "%d", find(list, m, 0, n-1));

	fclose(fr);
	fclose(fw);
}

int find(int* list, int m, int start, int end) {
	int mid = (start + end) / 2;
	if (list[mid] == m) {
		return mid;
	}
	else if (list[mid] < m) 
		return find(list, m, mid + 1, end);
	else
		return find(list, m, start, mid - 1);
}