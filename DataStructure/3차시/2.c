#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0:1)

typedef struct Item {
	int coef;
	int exp;
}item;

void polySum(int startA, int finishA, int startB, int finishB, item Terms[20]);

int main(void)
{
	FILE* fr = fopen("input.txt", "r");
	int n, m;

	item Terms[20];
	fscanf(fr, "%d %d", &n, &m);
	int startA, finishA;
	int coef, exp;
	startA = 0;
	for (int ii = 0; ii < n; ii++)
	{
		fscanf(fr, "%d %d", &coef, &exp);
		Terms[ii].coef = coef;
		Terms[ii].exp = exp;
		finishA = ii;
	}

	int startB, finishB;
	startB = finishA + 1;
	for (int ii = 0; ii < m; ii++)
	{
		fscanf(fr, "%d %d", &coef, &exp);
		Terms[startB + ii].coef = coef;
		Terms[startB + ii].exp = exp;
		finishB = startB + ii;
	}

	fclose(fr);
	polySum(startA, finishA, startB, finishB, Terms);
	return 0;
}

void polySum(int startA, int finishA, int startB, int finishB, item Terms[20])
{
	item Sum[20];
	int avail = 0;
	int expA, expB;
	int new_coef, new_exp;
	int coefA, coefB;
	while (startA <= finishA && startB <= finishB)
	{
		expA = Terms[startA].exp;
		expB = Terms[startB].exp;
		coefA = Terms[startA].coef;
		coefB = Terms[startB].coef;
		//printf("%d\n", COMPARE(expA, expB));
		//printf("%d %d %d %d\n", startA, finishA, startB, finishB);
		//printf("%d %d\n", expA, expB);
		switch (COMPARE(expA, expB))
		{
		case 0:
			new_coef = coefA + coefB;
			new_exp = expA;
			startA++; startB++;
			break;
		case 1:
			new_coef = coefA;
			new_exp = expA;
			startA++;
			break;
		case -1:
			new_coef = coefB;
			new_exp = expB;
			startB++;
			break;
		}

		Sum[avail].coef = new_coef;
		Sum[avail].exp = new_exp;
		avail++;

	}
	for (; startA <= finishA; startA++)
	{
		Sum[avail].coef = Terms[startA].coef;
		Sum[avail].exp = Terms[startA].exp;
		avail++;
	}
	for (; startB <= finishB; startB++)
	{
		Sum[avail].coef = Terms[startB].coef;
		Sum[avail].exp = Terms[startB].exp;
		avail++;
	}

	FILE* fw = fopen("output.txt", "w");
	int idx = 0;
	while (idx < avail)
	{
		fprintf(fw, "%d %d\n", Sum[idx].coef, Sum[idx].exp);
		idx++;
	}

	fclose(fw);
}