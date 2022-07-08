#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>

int min(int n, ...)
{
	int min, dum;

	va_list ap;
	va_start(ap, n);
	min = va_arg(ap, int);
	for (int i = 1; i < n; i++)
		if ((dum = va_arg(ap, int)) < min)
			min = dum;
	va_end(ap);

	return min;
	
}

int main(void)
{
	int count = 5;
	printf("ÃÖ¼Ú°ª: %d\n", min(count, 20, 30, 33, 99, 6));
	return 0;
}