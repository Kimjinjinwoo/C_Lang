#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int binary_search(int n, int m, int list[], int left, int right);

int main(void)
{
	FILE* fr = fopen("input.txt", "r");
	int n, m;
	int list[11];
	fscanf(fr, "%d %d", &n, &m);
	for (int ii = 0; ii < n;ii++)
		fscanf(fr, "%d", &list[ii]);
	fclose(fr);
	int ans = binary_search(n, m, list, 0, n-1);

	FILE* fw = fopen("output.txt", "w");
	fprintf(fw, "%d", ans);

}

int binary_search(int n, int m, int list[], int left, int right)
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (list[mid] == m)
			return mid;
		else if (list[mid] < m)
			return  binary_search(n, m, list, mid + 1, right);
		else
			return  binary_search(n, m, list, left, mid - 1);
	}
	return -1;
}