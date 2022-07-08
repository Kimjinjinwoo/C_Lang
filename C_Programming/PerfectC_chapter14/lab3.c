#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b);
int mult(int a, int b);
int subt(int a, int b);

int main(void)
{
	int (*pfunary[3])(int, int);
	pfunary[0] = add;
	pfunary[1] = mult;
	pfunary[2] = subt;

	int m = 8, n = 6;
	char* ops = "*+-";
	char op;
	while (op = *ops++)
		switch (op)
		{
		case '+':printf("%c 결과 %d\n", op, pfunary[0](m, n));
			break;
		case '-':printf("%c 결과 %d\n", op, pfunary[2](m, n));
			break;
		case '*':printf("%c 결과 %d\n", op, pfunary[1](m, n));
			break;
		}
	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int mult(int a, int b)
{
	return a * b;
}

int subt(int a, int b)
{
	return a - b;
}