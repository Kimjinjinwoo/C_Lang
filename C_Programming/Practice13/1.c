#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char fname[1000];
	scanf("%s", fname);

	FILE* f;
	//���� ����
	if (fopen_s(&f, fname, "r") != 0) {
		puts("����");
		exit(1);
	};

	char ch;
	while ((ch = fgetc(f)) != EOF)
	{
		printf("%c", ch);
	}
	fclose(f);
}