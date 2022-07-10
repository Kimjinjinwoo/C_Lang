#include <stdio.h>

void MaxAndMin(int*, int**, int**);

int main(void)
{
	int* maxPtr;
	int* minPtr;
	int arr[5] = {2,3,1,5,4};

	MaxAndMin(arr, &maxPtr, &minPtr);

	printf("%d %d", *maxPtr, *minPtr);
}

void MaxAndMin(int* arr, int** maxPtr, int** minPtr)
{
	int maxi = arr[0];
	int mini = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (maxi < arr[i])
		{
			maxi = arr[i];
			*maxPtr = &arr[i];
		}
		else if (mini > arr[i])
		{
			mini = arr[i];
			*minPtr = &arr[i];
		}
	}
}