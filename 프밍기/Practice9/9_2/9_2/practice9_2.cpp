#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print1DArray(int*, int n);

int main(void)
{
	int N;
	int nums[200];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	int* ptr = nums;
	for (int k = 0; k < N; k++)
	{
		print1DArray(nums + k, N - k);
	}
	return 0;
}

void print1DArray(int* nums, int n)
{
	for (int i = 0; i < n - 1; i++)
		printf("%d ", *(nums + i));
	printf("%d", *(nums + n - 1));
	puts("");
}