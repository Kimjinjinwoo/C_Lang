#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[1000001];

int main()
{
	gets(str);
	int len = strlen(str);
	int n0 = 0, n1 = 0;

	if (str[0] == '0')
		n0 += 1;
	else
		n1 += 1;
	char b = str[0];

	for (int i = 0; i < len; i++)
	{
		char ch = str[i];
		if (b != ch)
		{
			if (ch == '0')
				n0 += 1;
			else if (ch == '1')
				n1 += 1;

			b = ch;
		}

	}

	if (n1 >= n0)
		printf("%d", n0);
	else
		printf("%d", n1);


	return 0;
}