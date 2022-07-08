#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXBUFSIZE 100

void print1DArray(int a[], int n) {
	int i;
	for (int i = 0; i < n - 1; i++)
		printf("%d ", a[i]);
	printf("%d", a[n - 1]);
	printf("\n");
}

void main()
{
	int i, j;
	int* p[4] = { NULL };
	int a[4][5];


	for (int i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		p[i] = a[(1-i%2) * 2 + 1/2];
	}


	for (i = 0; i < 4; i++)
		print1DArray(p[i], 5);
}