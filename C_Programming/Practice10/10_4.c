#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void punct_ft(char*, char* , int , int*);

int main(void)
{
	char str[3][200];
	char punct[100];
	int a, b, c;
	gets(str[0]);
	gets(str[1]);
	gets(str[2]);

	int cnt = 0;

	for (int i = 0; i < 3; i++)
	{
		int n,k;
		n = strlen(str[i]);
		punct_ft(punct , str[i], n , &cnt);
	}
	punct[cnt] = '\0';

	printf("%d ", cnt);

	printf("%s", punct);

}

void punct_ft(char* punct, char* str, int n , int * pcnt)
{
	int cnt = *pcnt;
	for (int i = 0; i < n; i++)
	{
		if (ispunct(str[i]))
		{
			punct[*pcnt] = str[i];
			*pcnt += 1;
		}
	}
}