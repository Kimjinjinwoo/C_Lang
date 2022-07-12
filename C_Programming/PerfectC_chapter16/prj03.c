#include <stdio.h>
#include <stdlib.h>

void myprintf(int* ary, int n);

int main(void)
{
	int* ary = NULL;
	if ((ary = (int*)calloc(3, sizeof(int))) == NULL)
	{
		printf("¿¡·¯");
		exit(EXIT_FAILURE);
	}
	myprintf(ary, 3);

	free(ary);
	myprintf(ary, 3);

	return 0;
}

void myprintf(int* ary, int n)
{
	for (int i = 0; i < n; i++)
		printf("ary[%d] %d\n", i, *(ary + i));
}