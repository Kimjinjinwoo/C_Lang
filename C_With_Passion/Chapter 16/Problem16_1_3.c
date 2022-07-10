#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char sub[4][6] = { {"±¹¾î"} , {"¿µ¾î"} , {"¼öÇÐ"} , {"±¹»ç"} };
	char name[4][6] = { {"Ã¶Èñ"} , {"Ã¶¼ö"} , {"¿µÈñ"} , {"¿µ¼ö"} };

	int table[5][5] = {0};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%sÀÇ %s ¼ºÀû: ", name[i], sub[j]);
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