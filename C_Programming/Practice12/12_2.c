#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char name[20];
	char number[20];
}check;

void input(check*, int);
char* search(check*, int, char str[]);

int main(void)
{
	int N;
	scanf("%d", &N);
	check checkList[30];

	input(checkList , N);

	char str[30];
	scanf("%s", str);

	char* ansnum = search(checkList, N, str);
	printf("%s", ansnum);
}

void input(check* List, int N)
{
	for (int i = 0; i < N; i++)
	{
		scanf("%s %s", List[i].name, List[i].number);
	}
}

char* search(check* List, int N, char str[])
{
	for (int i = 0; i < N; i++)
	{
		if (!strcmp(str, List[i].name))
			return List[i].number;
	}
}

