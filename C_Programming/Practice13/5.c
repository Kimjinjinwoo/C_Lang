#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

typedef struct ss
{
	char name[20];
	double num1;
	double num2;
	double num3;
	double mean;
}student;


int main(void)
{
	char fname[20];
	gets(fname);

	student ss;

	FILE* f;
	if (fopen_s(&f, fname, "r") != 0)
	{
		puts("¿¡·¯");
		exit(1);
	}

	char str[50];
	fgets(str,40, f);
	int cnt = 0;

	while (!feof(f))
	{
		sscanf_s(str, "%s %lf %lf %lf", ss.name,50, &ss.num1, &ss.num2, &ss.num3);
		ss.mean = (ss.num1 + ss.num2+ss.num3) / 3;
		printf("%s\t%.0lf\t%.0lf\t%.0lf\t%.2lf\n",
			ss.name, ss.num1, ss.num2, ss.num3, ss.mean);
		//puts(str);
		fgets(str,40, f);
	}

	fclose(f);

	return 0;
}