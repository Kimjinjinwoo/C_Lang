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


int main(void)
{
	lecture course[5];
	puts("�Է�");
	for (int i = 0; i < 5; i++)
	{
		scanf("%s %d %d %d", &course[i].name, &course[i].type, &course[i].credit, &course[i].hours);
	}

	puts("���");
	for (int i = 0; i < 5; i++)
	{
		printf("%s %d %d %d", course[i].name, course[i].type, course[i].credit, course[i].hours);
		puts("");
	}

	return 0;
}