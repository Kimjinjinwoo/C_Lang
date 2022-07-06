#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void minMax(int*, int, int*, int*);

int main(void)
{
	int N;
	int nums[200];
	int min = 0, max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	minMax(nums, N, &min, &max);
	printf("%d %d", max, min);
	return 0;
}

void minMax(int* data, int n, int* min, int* max)
{
	*min = data[0];
	*max = data[0];
	for (int i = 0; i < n; i++)
	{
		int num;
		num = data[i];
		if (num < *min)
			*min = num;
		if (num > *max)
			*max = num;
	}
}