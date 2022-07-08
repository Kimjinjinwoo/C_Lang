#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void add_array(double*, double*, double*, int);

int main(void)
{
	int N;
	scanf("%d", &N);

	double nums1[30], nums2[30];
	double target[30];
	for (int i = 0; i < N; i++)
		scanf("%lf", &nums1[i]);

	for (int i = 0; i < N; i++)
		scanf("%lf", &nums2[i]);

	add_array(nums1, nums2, target, N);

	for (int i = 0; i < N - 1; i++)
		printf("%.2lf ", target[i]);
	printf("%.2lf", target[N - 1]);

	return 0;
}


void add_array(double source1[], double source2[], double target[], int num)
{
	for (int i = 0; i < num; i++)
	{
		*(target + i) = source1[i] + source2[i];
	}
}