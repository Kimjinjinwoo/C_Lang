#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char inName[1000], outName[1000];
	scanf("%s", inName);
	scanf("%s", outName);

	FILE* f1, * f2;
	if (fopen_s(&f1, inName, "r") != 0)
	{
		puts("에러");
		exit(1);
	}

	if (fopen_s(&f2, outName, "w") != 0)
	{
		puts("에러2");
		fclose(1);
		exit(1);
	}

	char a;
	while ((a = getc(f1)) != EOF)
	{
		if (isalpha(a))
			if (islower(a))
				a = toupper(a);
		printf("%c", a);
		fputc(a, f2);
	}

	fclose(f1);
	fclose(f2);

	return 0;
}