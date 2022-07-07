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

char* head[] = { "���¸�" , "���±���" , "����" , "�ü�" };
char* lectype[] = { "����" , "�Ϲݼ���" , "�����ʼ�","��������" };

void printStruct(lecture *);

int main(void)
{
	lecture os = { "�ü��" , 2,3,3 };
	lecture c = { "C���α׷���" , 3,3,4 };
	lecture* p = &os;

	printStruct(p);
}

void printStruct(lecture* p)
{
	printf("����ü ũ��: %zu, ������ ũ��: %zu\n\n", sizeof(*p), sizeof(p));
	printf("%10s %12s %6s %6s\n", head[0], head[1], head[2], head[3]);
	printf("%12s %10s %5d %5d\n", p->name, lectype[p->type], p->credit, p->hours);
}