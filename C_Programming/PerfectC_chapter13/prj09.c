#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct lecture
{
	char name[20];
	int type;
	int credit;
	int hours;
};

typedef struct lecture lecture;

char* head[] = { "강좌명" , "강좌구분" , "학점" , "시수" };
char* lectype[] = { "교양" , "일반선택" , "전공필수","전공선택" };


int main(void)
{
	lecture course[5];
	puts("입력");
	for (int i = 0; i < 5; i++)
	{
		scanf("%s %d %d %d", &course[i].name, &course[i].type, &course[i].credit, &course[i].hours);
	}

	puts("출력");
	for (int i = 0; i < 5; i++)
	{
		printf("%s %d %d %d", course[i].name, course[i].type, course[i].credit, course[i].hours);
		puts("");
	}

	return 0;
}