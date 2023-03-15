#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0:1)
void polySum(int startA, int finishA, int startB, int finishB, int Terms[][2]);

int main(void)
{
	FILE* fr = fopen("input.txt", "r");
	int n, m;
	int Terms[20][2];
	
	fscanf(fr, "%d %d", &n, &m);
	int startA, finishA;
	int coef, exp;
	startA = 0;
	for (int ii = 0; ii < n; ii++)
	{
		fscanf(fr, "%d %d", &coef, &exp);
		Terms[ii][0] = coef;
		Terms[ii][1] = exp;
		finishA = ii;
	}

	int startB, finishB;
	startB = finishA + 1;
	for (int ii = 0; ii < m; ii++)
	{
		fscanf(fr, "%d %d", &coef, &exp);
		Terms[startB + ii][0] = coef;
		Terms[startB + ii][1] = exp;
		finishB = startB + ii;
	}

	fclose(fr);
	polySum(startA, finishA, startB, finishB, Terms);
	return 0;
}

void polySum(int startA, int finishA, int startB, int finishB, int Terms[20][2])
{
	int Sum[20][2];
	int avail = 0;
	int expA, expB;
	int new_coef, new_exp;
	int coefA, coefB;
	while (startA <= finishA && startB <= finishB)
	{
		expA = Terms[startA][1];
		expB = Terms[startB][1];
		coefA = Terms[startA][0];
		coefB = Terms[startB][0];
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
		
		Sum[avail][0] = new_coef;
		Sum[avail][1] = new_exp;
		avail++;

	}
	for (; startA <= finishA; startA++)
	{
		Sum[avail][0] = Terms[startA][0];
		Sum[avail][1] = Terms[startA][1];
		avail++;
	}
	for (; startB <= finishB; startB++)
	{
		Sum[avail][0] = Terms[startB][0];
		Sum[avail][1] = Terms[startB][1];
		avail++;
	}
	
	FILE* fw = fopen("output.txt", "w");
	int idx = 0;
	while (idx < avail)
	{
		fprintf(fw, "%d %d\n",Sum[idx][0] ,Sum[idx][1] );
		idx++;
	}

	fclose(fw);
}