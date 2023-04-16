#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	int n, m;
	fscanf(fr, "%d %d", &n, &m);
	int* list = (int*)malloc(sizeof(int) * n);
	
	for (int ii = 0; ii < n; ii++)
		fscanf(fr, "%d", &list[ii]);

	// find!!
	FILE* fw = fopen("output.txt", "w");
	int start = 0, end = n - 1;
	while (1){
		int mid = (start + end) / 2;
		if (list[mid] == m) {
			fprintf(fw, "%d", mid);
			break;
		}
		else if (list[mid] < m)
			start = mid + 1;
		else
			end = mid - 1;
	}

	fclose(fr);
	fclose(fw);
}