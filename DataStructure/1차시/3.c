#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 21;

int main(void)
{
	FILE* fr = fopen("input.txt", "r");
	int n;
	fscanf(fr, "%d", &n);
	int A[21][21], B[21][21];
	// A initial
	for (int ii = 0; ii < n; ii++)
	{
		for (int jj = 0; jj < n; jj++)
	{
			fscanf(fr, "%d", &A[ii][jj]);
	}
	}
	// B initial
	for (int ii = 0; ii < n; ii++)
	{
		for (int jj = 0; jj < n; jj++)
		{
			fscanf(fr, "%d", &B[ii][jj]);
		}
	}
	int C[21][21];

	for (int ii = 0; ii < n; ii++)
		{
			for (int jj = 0; jj < n; jj++)
			{	
				int tmp = 0;
				for (int kk = 0; kk < n; kk++)
					tmp += A[ii][kk] * B[kk][jj];
				C[ii][jj] = tmp;
			}
		}
	fclose(fr);
		// Ãâ·Â
	FILE* fw = fopen("output.txt", "w");
	for (int ii = 0; ii < n; ii++)
	{
		for (int jj = 0; jj < n; jj++)
		{
			fprintf(fw, "%d ", C[ii][jj]);

		}
		fprintf(fw, "\n");
	}
	fclose(fw);
}