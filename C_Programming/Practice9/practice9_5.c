#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sortWithoutDuplication(int*, int*);

int main(void)
{
	int size = 10;
	int nums[200];
	for (int i = 0; i < 10; i++)
		scanf("%d", &nums[i]);
	sortWithoutDuplication(nums, &size);

	for (int i = 0; i < size; i++)
	{
		printf("%d", nums[i]);
		if (i < size - 1)
			printf(" ");
	}
	return 0;
}

void sortWithoutDuplication(int arry[], int* size)
{

	for (int i = 0; i < *size; i++)
	{
		for (int j = 0; j < *size - i - 1; j++)
		{
			if (arry[j + 1] < arry[j])
			{
				int temp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = temp;
			}
		}

		int back = arry[0];

		for (int i = 1; i < *size; i++)
		{
			int num = arry[i];
			if (num == back)
			{
				for (int j = i + 1; j < *size; j++)
				{
					arry[j - 1] = arry[j];
				}
				*size = *size - 1;
			}
			back = num;
		}
	}
}