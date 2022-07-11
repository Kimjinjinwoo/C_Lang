#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

char fname1[20], fname2[20];



int main(void)
{
	
	FILE* f1, * f2;
	gets(fname1);
	gets(fname2);

	if (fopen_s(&f1, fname1, "r")!=0)
	{
		puts("에러");
		exit(1);
	}

	if (fopen_s(&f2, fname2, "w") != 0)
	{
		puts("에러");
		fclose(f1);
		exit(1);
	}
	char ch;
	int sum = 0;

	int cnt = 0;
	while ( (ch = getc(f1)) != EOF)
	{
		if (isdigit(ch))
		{
			sum += (int)ch - (int)'0';
			fputc(ch, f2);
		}
	}
	

	printf("%d", sum);
	fclose(f1);
	fclose(f2);

	return 0;
}