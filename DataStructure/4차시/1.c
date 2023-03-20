#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
	int col;
	int row;
	int value;
} term;

void sol(int N, int** Matrix);
term* makeSparse(int N, int** Matrix);
term* FastTransposing(term* Sparse);


int main(void)
{
	FILE* fr = fopen("input.txt", "r");
	int N;
	fscanf(fr, "%d", &N);
	int** Matrix = (int**)malloc(sizeof(int) * N);
	for (int ii = 0; ii < N; ii++)
	{
		Matrix[ii] = (int*)malloc(sizeof(int) * N);
	}


	for (int ii = 0; ii < N; ii++)
	{
		for (int jj = 0; jj < N; jj++)
		{
			fscanf(fr, "%d", &Matrix[ii][jj]);
		}
	}
	fclose(fr);
	sol(N, Matrix);
	return 0;
}

void sol(int N, int** Matrix)
{
	term* Sparse = makeSparse(N, Matrix);
	term* transposed = FastTransposing(Sparse);


	FILE* fw = fopen("output.txt", "w");
	fprintf(fw, "%d\n", transposed[0].value);

	for (int ii = 1; ii < transposed[0].value + 1; ii++)
	{
		fprintf(fw, "%d %d %d\n", transposed[ii].row, transposed[ii].col, transposed[ii].value);
	}
	fclose(fw);
	free(transposed);
	free(Matrix);
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

term* FastTransposing(term* Sparse)
{
	int N, NumElements;
	int row;
	N = Sparse[0].row;
	NumElements = Sparse[0].value;
	// row Terms¸¸µé±â
	int* rowTerms = (int*)malloc(sizeof(int) * N);
	for (int ii = 0; ii <= N; ii++)
	{
		rowTerms[ii] = 0;
	}

	for (int ii = 1; ii <= NumElements; ii++)
	{
		row = Sparse[ii].col;
		rowTerms[row]++;
	}

	//startingPos ¸¸µé±â
	int start = 1;
	int* startingPos = (int*)malloc(sizeof(int) * N);


	for (int ii = 0; ii < N; ii++)
	{
		startingPos[ii] = start;
		start += rowTerms[ii];
		//printf("%d\n", start);
	}

	// ÁøÂ¥ transpose
	term* transposed = (term*)malloc(sizeof(term) * (NumElements + 1));
	transposed[0].row = N;
	transposed[0].col = N;
	transposed[0].value = NumElements;

	for (int ii = 1; ii < NumElements + 1; ii++)
	{
		int col = Sparse[ii].col;
		int idx = startingPos[col];
		startingPos[col]++;
		//printf("%d   %d\n", idx, NumElements);
		transposed[idx].row = Sparse[ii].col;
		transposed[idx].col = Sparse[ii].row;
		transposed[idx].value = Sparse[ii].value;
	}

	//free(Sparse);
	//free(startingPos);
	//free(rowTerms);
	return transposed;
}