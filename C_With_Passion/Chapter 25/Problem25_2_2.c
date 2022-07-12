#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int lmt = 5;
	int* pi = (int*)malloc(sizeof(int) * lmt);

	int k = 0, num = 0;
	
	while (num != -1 )
	{
		if (k == lmt)
		{
			lmt += 3;
			pi = realloc(pi, sizeof(int) * lmt);
		}
		scanf("%d", &num);
		*(pi + k) = num;
		k++;
	}
	puts("Ãâ·Â");
	for (int i = 0; i < k-1; i++)
	{
		printf("%d ", pi[i]);
	}

	free(pi);
	return 0;
}