//배열 크기 입력 받아서
//메모리 할당
//데이터 입력하고 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* pi = NULL;
	int size_;
	scanf("%d", &size_);

	pi = (int*)malloc(sizeof(int) * size_);

	for (int i = 0; i < size_; i++)
	{
		scanf("%d", pi + i);
	}

	
	if (pi == NULL)
	{
		printf("에러");
		exit(1);
	}

	for (int i = 0; i < size_; i++)
	{

		printf("주소값: *pi = %p, 저장 값: p = %d\n", pi+i, *(pi+i));
	}

	

}