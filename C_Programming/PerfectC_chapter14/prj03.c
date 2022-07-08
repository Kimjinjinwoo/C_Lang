#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>

double avg(int, ...);

int main(void)
{
	printf("ЦђБе %.2f\n", avg(5, 1.2, 2.1, 3.6, 4.3, 5.8));
	printf("ЦђБе %.2f\n", avg(6, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0));

	return 0;
}

double avg(int numargs, ...)
{
	double total = 0;

	va_list argp;
	va_start(argp, numargs);
	for (int i = 0; i < numargs; i++)
		total += va_arg(argp, double);
	va_end(argp);

	return total / numargs;
}