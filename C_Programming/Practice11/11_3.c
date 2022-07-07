#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct boon 
{
	int son;
	int mother;
}bs;

void bsCmp(bs, bs);

int main(void)
{
	bs bs1;
	bs bs2;

	scanf("%d/%d", &bs1.son, &bs1.mother);
	scanf("%d/%d", &bs2.son, &bs2.mother);

	bsCmp(bs1, bs2);

	return 0;
}

void bsCmp(bs bs1, bs bs2)
{
	int num1, num2;
	num1 = bs1.son * bs2.mother;
	num2 = bs2.son * bs1.mother;

	if (num1 > num2)
		printf("-1");
	else if (num1 == num2)
		printf("0");
	else
	{
		printf("1");
	}
}