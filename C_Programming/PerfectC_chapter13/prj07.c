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

void printStruct(lecture *);

int main(void)
{
	lecture os = { "운영체제" , 2,3,3 };
	lecture c = { "C프로그래밍" , 3,3,4 };
	lecture* p = &os;

	printStruct(p);
}

void printStruct(lecture* p)
{
	printf("구조체 크기: %zu, 포인터 크기: %zu\n\n", sizeof(*p), sizeof(p));
	printf("%10s %12s %6s %6s\n", head[0], head[1], head[2], head[3]);
	printf("%12s %10s %5d %5d\n", p->name, lectype[p->type], p->credit, p->hours);
}