#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
	char fname[100];
	int calories;
}Food;

int totalCalories(Food[40], int);

int main()
{
	Food arr[40];
	int total=0;
	int i = 0;
	while (1)
	{
		scanf("%s", arr[i].fname);
		
		if (!strcmp(arr[i].fname , "quit"))
			break;

		scanf("%d", &arr[i].calories);
		i++;
	}

	total = totalCalories(arr, i);
	printf("%d", total);
	return 0;
}

int totalCalories(Food ary[], int size)
{
	int snum = 0;
	for (int i = 0; i < size; i++)
	{
		snum += ary[i].calories;
	}

	return snum;
}