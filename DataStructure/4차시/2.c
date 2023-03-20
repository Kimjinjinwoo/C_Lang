/*
* 입력을
* N N Elements
* ...
* ...
* 으로 생각
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
	int col;
	int row;
	int value;
} term;

term* makeSparse(int N, int** Matrix);

int main(void)
{
	int N1, NumElements1;
	FILE* fr1 = fopen("input1.txt", "r");
	fscanf(fr1, "%d %d %d", &N1, &N1, &NumElements1);
	term* Mat1 = (term*)malloc(sizeof(term) * (NumElements1 + 1));
	Mat1[0].row = N1; Mat1[0].col = N1; Mat1[0].value = NumElements1;
	for (int ii = 0; ii < NumElements1 + 1; ii++)
	{
		printf("%d ", ii);
		fscanf(fr1, "%d %d %d", &Mat1[ii].row, &Mat1[ii].col, &Mat1[ii].value);
	}

	int N2, NumElements2;
	FILE* fr2 = fopen("input2.txt", "r");
	fscanf(fr2, "%d %d %d", &N2, &N2, &NumElements2);
	term* Mat2 = (term*)malloc(sizeof(term) * (NumElements2 + 1));
	Mat2[0].row = N1; Mat2[0].col = N2; Mat2[0].value = NumElements2;
	for (int ii = 0; ii < NumElements2 + 1; ii++)
	{
		fscanf(fr2, "%d %d %d", &Mat2[ii].row, &Mat2[ii].col, &Mat2[ii].value);
	}

	fclose(fr1);
	fclose(fr2);

	// 근데 곱 할라면 N이 같아야 되잖아. 개이득
	// 시간 복잡도 개구리게 풀어야지....
	int N = N1;
	int** Matrix = (int**)malloc(sizeof(int) * N);
	for (int ii = 0; ii < N; ii++)
	{
		Matrix[ii] = (int*)malloc(sizeof(int) * N);
	}
	for (int ii = 0; ii < N; ii++)
	{
		for (int jj = 0; jj < N; jj++)
		{
			Matrix[ii][jj] = 0;
		}
	}

	int row, col;

	for (int aa = 0; aa < NumElements1; aa++)
	{
		row = Mat1[aa].row;
		for (int bb = 0; bb < NumElements2; bb++)
		{
			col = Mat2[bb].col;
			if (Mat1[aa].col == Mat2[bb].row)
			{
				printf("%d %d\n", row, col);
				printf("%d %d\n\n\n", aa, bb);
				Matrix[row][col] += Mat1[aa].value * Mat2[bb].value;
			}
		}
	}
	term* Sparse = makeSparse(N, Matrix);

	FILE* fw = fopen("output.txt", "w");
	for (int ii = 0; ii < Sparse[0].value + 1; ii++)
	{
		fprintf(fw, "%d %d %d\n", Sparse[ii].row, Sparse[ii].col, Sparse[ii].value);
	}

	return 0;
}


term* makeSparse(int N, int** Matrix)
{
	term* Sparse = (term*)malloc(sizeof(term));
	int NumElements = 0;
	int value;
	for (int ii = 0; ii < N; ii++)
	{
		for (int jj = 0; jj < N; jj++)
		{
			value = Matrix[ii][jj];
			if (value != 0)
			{
				NumElements++;

				Sparse = realloc(Sparse, sizeof(term) * (NumElements + 1));
				Sparse[NumElements].row = ii;
				Sparse[NumElements].col = jj;
				Sparse[NumElements].value = value;

			}
		}
	}
	Sparse[0].row = N;
	Sparse[0].col = N;
	Sparse[0].value = NumElements;

	return Sparse;
}
