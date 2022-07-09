#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void change(char* , int*, int);
char str[100001];
int wordidx[100001] = { 0 };

int main(void)
{	
	int n;
	gets(str);

	n = strlen(str);
	int len = 0;
	int isWord = 1;

	for (int i = 0; i < n; i++)
	{
		char ch = str[i];
		if (ch == '<')
		{
			isWord = 0;
			change(str, wordidx, len);
			len = 0;
			continue;
		}
		else if (ch == '>')
		{
			isWord = 1;
			continue;
		}
		else if (ch == ' ')
		{
			isWord = 1;
			change(str , wordidx, len);
			len = 0;
			continue;
		}

		if (isWord == 1)
		{
			wordidx[len] = i;
			len += 1;
		}
	}

	change(str, wordidx, len);

	puts(str);
}

void change(char* str ,int* wordidx, int N)
{
	for (int i = 0; i < N; i++)
	{
		char temp = str[i];
		str[i] = str[N - i-1];
		str[N - i - 1 ] = temp;
	}

}