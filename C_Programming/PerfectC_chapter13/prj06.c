#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct date
{
	int year;
	int month;
	int day;
};


typedef struct date date;

typedef struct
{
	char title[30];
	char company[30];
	char kinds[30];
	date release;
} software;

void print_struct(software);

int main(void)
{

	software vs = { "비주얼 스튜디오 커뮤니티" , "MS" , "통합개발환경" , {2022 , 8 , 29} };

	print_struct(vs);
	return 0;
}

void print_struct(software vs)
{
	puts("함수 실행");
	printf("%s %s %s\n" , vs.title , vs.company , vs.kinds);
	printf("%d %d %d", vs.release.year, vs.release.month, vs.release.day);
}