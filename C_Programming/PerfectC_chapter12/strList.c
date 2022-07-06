#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void input(char arr[][20], int N);

int main()
{
	char str[5][20];

	input(str , 5);

	for (int i = 0; i < 5; i++)
	{
		puts(str[i]);
	}

	return 0;
}

void input(char arr[][20], int N)
{
	for (int i = 0; i < N; i++)
	{
		gets(arr[i]);
	}
}
