#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char sub[4][6] = { {"����"} , {"����"} , {"����"} , {"����"} };
	char name[4][6] = { {"ö��"} , {"ö��"} , {"����"} , {"����"} };

	int table[5][5] = {0};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%s�� %s ����: ", name[i], sub[j]);
			scanf("%d", &table[i][j]);
			table[4][j] += table[i][j];
			table[i][4] += table[i][j];
			table[4][4] += table[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", table[i][j]);
		}
		puts("");
	}

}