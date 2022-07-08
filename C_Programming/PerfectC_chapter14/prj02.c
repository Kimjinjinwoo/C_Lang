#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//함수 만들어서 데이터 입력받기 && 출력
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
	printf("main()에서 구한 합은 %d\n", sum);

	printf("함수 sumary() 호출로 구한 합은 %d\n", sumary(arr, N));

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