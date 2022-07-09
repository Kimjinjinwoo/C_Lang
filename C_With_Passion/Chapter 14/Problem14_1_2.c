#include <stdio.h>

void Swap3(int*, int*, int*);

int main(void)
{
	int num1 = 1, num2 = 2, num3 = 3;
	Swap3(&num1, &num2, &num3);
	printf("%d %d %d", num1 , num2 , num3);
}

void Swap3(int* p1, int* p2, int* p3)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = *p3;
	*p3 = temp;
}