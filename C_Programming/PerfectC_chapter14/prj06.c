#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void devideandincrement(double*, double*, double*);

int main(void)
{
	double m = 0, n = 0, mult = 0, dev = 0;

	printf("�� �Ǽ� �Է�: ");
	scanf("%lf %lf", &m, &n);

	devideandincrement(&dev , &m , &n);
	printf("�� �Ǽ� ��: %.2f, ����: %.2f\n" , mult , dev);
	printf("���� �� �� �Ǽ�: %.2f, %.2f\n" , m , n);

	return 0;
}

void devideandincrement(double* result, double* a, double* b)
{
	*result = *a / *b;
	++* a;
	(*b)++;
}