#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0:1)

typedef struct Item {
	int coef;
	int exp;
}item;

void polySum(int startA, int finishA, int startB, int finishB, item* Terms);

int main(void)
{
	FILE* fr = fopen("input.txt", "r");
	int n, m;

	fscanf(fr, "%d %d", &n, &m);
	item* Terms = (item*)malloc(sizeof(item) * (n + m));
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
	free(Terms);
	return 0;
}

void polySum(int startA, int finishA, int startB, int finishB, item* Terms)
{
	item* Sum = (item*)malloc(sizeof(item));
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
		realloc(Sum, sizeof(item) * (avail + 1));
		Sum[avail].coef = new_coef;
		Sum[avail].exp = new_exp;
		avail++;

	}
	for (; startA <= finishA; startA++)
	{
		realloc(Sum, sizeof(item) * (avail + 1));
		Sum[avail].coef = Terms[startA].coef;
		Sum[avail].exp = Terms[startA].exp;
		avail++;
	}
	for (; startB <= finishB; startB++)
	{
		realloc(Sum, sizeof(item) * (avail + 1));
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
	free(Sum);
	fclose(fw);
}