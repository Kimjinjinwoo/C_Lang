#include <stdio.h>

int SqureByValue(int N);
void SqureByReference(int* ptr);

int main()
{
	int N = 3;
	int sq = SqureByValue(N);
	printf("%d\n", sq);

	SqureByReference(&N);
	printf("%d", N);
}

int SqureByValue(int N)
{
	return N * N;
}

void SqureByReference(int* ptr)
{
	*ptr = *ptr * *ptr;
}