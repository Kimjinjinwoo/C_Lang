#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct personscore
{
	int number;
	char name[40];
	int mid;
	int final;
	int quiz;
}pscore;

void printhead()
{
	printf("%s\n", "  --------------------------");
	printf("%8s%15s%10s%8s%8s\n", "��ȣ", "�̸�", "�߰�" , "�⸻" , "����");
	printf("%s\n", "  --------------------------");
}

int main()
{
	char fname[] = "score.bin";
	FILE* f;

	if (fopen_s(&f, fname, "wb") != 0)
	{
		printf("�ȵ�\n");
		exit(1);
	};

	char line[80];
	int cnt = 0;
	pscore score;
	printf("�̸��� ����(�߰�, �⸻, ����)�� �Է��ϼ���.\n");

	fgets(line, 80, stdin);
	while (!feof(stdin))
	{
		sscanf_s(line, "%s %d %d %d", score.name, 40, &score.mid, &score.final, &score.quiz);

		score.number =++cnt;
		fwrite(&score, sizeof(pscore), 1, f);
		fgets(line, 80, stdin);
	}
	fclose(f);

	if ((f = fopen(fname, "rb")) == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	};
	printhead();

	fread(&score, sizeof(pscore), 1, f);

	while (!feof(f))
	{
		fprintf(stdout, "%6d%18s%8d%8d%8d\n",
			score.number, score.name, score.mid, score.final, score.quiz);
		fread(&score, sizeof(pscore), 1, f);
	}
	printf("%s\n", "   ----------------------------");
	fclose(f);
 
	return 0;
}