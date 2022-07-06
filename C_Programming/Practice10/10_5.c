#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void strSort(char str[][50], int n);
int order[10] = { 0,1,2,3,4,5,6,7,8,9 };

int main(void)
{
	char str[10][50] = { '\0' };
	int i = 0;
	while (gets(str[i]))
	{
		i++;
	}
	strSort(str, i);
	for (int k = 0; k < i; k++)
	{
		int n = order[k];
		for (int i = 0; i < 49; i++)
		{
			char c = str[n][i];
			if (c == ' ' || c == '\0')
			{
				printf("\n");
				break;
			}
			else
			{
				printf("%c", c);
			}
		}
	}
}

void strSort(char str[][50], int N)
{

	for (int n = 49; n >= 0; n--)
	{
		//여기부터 정렬
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				int a = order[j], b = order[j + 1];
				if ((int)str[a][n] > (int) str[b][n])
				{
					order[j + 1] = a;
					order[j] = b;
				}
			}
		}
	}
}