#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char fname[] = "grade.txt";
	char* name[40];
	int cnt = 0;

	FILE* f;

	if (fopen_s(&f, fname, "w") != 0)
	{
		printf("�� �ȵǴµ�?\n");
		exit(1);
	}

	puts("�̸��� ����(�߰�, �⸻)�� �Է��ϼ���.\n");

	fgets(name, 40, stdin);

	while (!feof(stdin))
	{
		fprintf("f, %d ", ++cnt);
		fputs(name, f);
		fgets(name, 40, stdin);
	}
	fclose(f);

	return 0;
}