#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//구조체 정의

struct date
{
	int year;
	int month;
	int day;
};

struct account
{
	struct date open;
	char name[12];
	int actnum;
	double balance;
};



int main()
{
	struct account yours;
	
	puts("입력>>");
	scanf("%d %d %d", &yours.open.year, &yours.open.month , &yours.open.day);
	scanf("%s", &yours.name);
	scanf("%d", &yours.actnum);
	scanf("%lf", &yours.balance);

	puts("");

	puts("출력>>");
	printf("%d %d %d\n", yours.open.year, yours.open.month, yours.open.day);
	printf("%s\n", yours.name);
	printf("%d\n", yours.actnum);
	printf("%lf\n", yours.balance);

	return 0;
}