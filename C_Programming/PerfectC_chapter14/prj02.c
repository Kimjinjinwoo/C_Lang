#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�Լ� ���� ������ �Է¹ޱ� && ���
void inputList(int*, int);
void printList(int*, int);
int sumary(int*, int);

int main(void)
{
	int N;
	int arr[50] = {0};
	scanf("%d", &N);
	inputList(arr, N);

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += *(arr + i);
	printf("main()���� ���� ���� %d\n", sum);

	printf("�Լ� sumary() ȣ��� ���� ���� %d\n", sumary(arr, N));

	printList(arr, N);
	return 0;
}

void inputList(int* arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void printList(int* arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d", arr[i]);
	}
}
int sumary(int* arr, int SIZE)
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += *arr++;
	}

	return sum;
}