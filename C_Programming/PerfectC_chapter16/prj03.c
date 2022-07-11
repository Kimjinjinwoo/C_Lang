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
		printf("또 안되는디?\n");
		exit(1);
	}

	puts("이름과 성적(중간, 기말)을 입력하세요.\n");

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