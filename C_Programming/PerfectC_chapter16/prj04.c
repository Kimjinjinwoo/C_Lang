#include <stdio.h>
#include <stdlib.h>
void myprintf(int* ary , int n);

int main(void)
{
	int* reary, * cary;
	if ((cary = (int*)calloc(3, sizeof(int))) == NULL)
	{
		printf("메모리 할당이 문제가 있습니다.\n");
		exit(EXIT_FAILURE);
	}
	printf("%p\n", cary);
	cary[0] = 10;

	if ((reary = (int*)realloc(cary, 4 * sizeof(int))) == NULL)
	{
		printf("에러");
		exit(EXIT_FAILURE);
	}
	printf("%p\n", reary);

	myprintf(reary, 4);
	free(reary);
	return 0;
}

void myprintf(int* ary, int n)
{
	for (int i = 0; i < n; i++)
		printf("ary[%d] %d\n", i, *(ary + i));
}