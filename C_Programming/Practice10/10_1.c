#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1000];

	gets(str);

	char* ptoken = strtok(str , " ");
	while (1)
	{
		int n = strlen(ptoken);
		for (int i = n - 1; i >= 0; i--)
		{
			printf("%c", ptoken[i]);
		}
		ptoken = strtok(NULL, " ");
		if (ptoken)
			printf(" ");
		else
			break;
	}
	return 0;
}