//����ü���� ���� �ΰ�
//����ü �迭�� �������� �Ҵ�
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

	puts("���");

	for (int i = 0; i < size_; i++)
	{
		printf("%d %d\n", (pi + i)->num1, (pi + i)->num2);
	}

	free(pi);
	return 0;
}