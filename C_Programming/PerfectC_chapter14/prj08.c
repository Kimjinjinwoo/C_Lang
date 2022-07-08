#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void add(double*, double, double);

int main(void)
{
	void (*pf)(double*, double, double) = NULL;

	double m, n, result = 0;
	printf("�Ǽ� �ΰ� ������: ");
	scanf("%lf %lf", &m, &n);

	pf = add;
	pf(&result, m, n);
	printf("���� �����: %lf + %lf == %lf\n", m, n, result);
	printf("%p %p\n", pf, add);

	return 0;
}

void add(double* result, double a, double b)
{
	*result = a + b;
}