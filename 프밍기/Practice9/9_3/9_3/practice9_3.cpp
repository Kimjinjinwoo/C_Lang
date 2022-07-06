#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void findSum(int*, int, int*);

int main(void)
{
	int N;
	int nums[200];
	int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	findSum(nums, N, &sum);

	printf("%d", sum);
	return 0;
}

void findSum(int* data, int n, int* sum)
{
	for (int i = 0; i < n; i++)
	{
		*sum += data[i];
	}
}