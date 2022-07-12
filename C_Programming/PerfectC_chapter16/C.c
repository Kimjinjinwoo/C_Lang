//구조체에서 정수 두개
//구조체 배열을 동적으로 할당
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num1;
	int num2;
}numbers;

int main(void)
{
	int size_;
	scanf("%d", &size_);
	numbers* pi = (numbers*)malloc(sizeof(numbers) * size_);
	for (int i = 0; i < size_; i++)
	{
		scanf("%d %d", &(pi + i)->num1, &(pi + i)->num2);
	}

	puts("출력");

	for (int i = 0; i < size_; i++)
	{
		printf("%d %d\n", (pi + i)->num1, (pi + i)->num2);
	}

	free(pi);
	return 0;
}