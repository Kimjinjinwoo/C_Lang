#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	struct student
	{
		int snum;
		char dept[12];
		char name[12];
	};

	struct student A;
	struct student B;

	scanf("%d %s %s", &A.snum, &A.dept, &A.name);
	scanf("%d %s %s", &B.snum, &B.dept, &B.name);

	if (A.snum == B.snum)
		printf("학번이 %d로 동일합니다.\n", A.snum);

	if (A.snum == B.snum && !strcmp(A.dept, B.dept) && !strcmp(A.name, B.name))
		printf("내용이 같은 구조체입니다.\n");

	return 0;
}