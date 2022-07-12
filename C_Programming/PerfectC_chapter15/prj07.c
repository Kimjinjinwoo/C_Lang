#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct personscore
{
	int number;
	char name[40];
	int mid;
	int final;
	int quiz;
};
typedef struct personscore pscore;

void printhead();
int printscore(FILE* f);
void appendscore(FILE* f, int cnt);

int main()
{
	FILE* f;
	char fname[] = "score.bin";
	int cnt = 0;
	long offset = 0;

	if ((f = fopen(fname, "ab+")) == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}

	int readcnt = printscore(f);
	if (readcnt == 1)
	{
		pscore score;
		offset = (long)sizeof(pscore);
		fseek(f, -offset, SEEK_END); //�� �л� ��ŭ �ڷ�
		cnt = score.number;
		printf("\n���� ������ ��ȣ�� %d�� �Դϴ�. \n\n", cnt);
	}
	fseek(f, 0L, SEEK_END);
	appendscore(f, cnt);
	printscore(f);
	fclose(f);

	return 0;
}

void appendscore(FILE* f, int cnt)
{
	char line[80];
	pscore score = { 0 };
	printf("�߰��� �̸��� ����(�߰�, �⸻, ����)�� �Է��ϼ���.\n\n");
	fgets(line, 80, stdin);
	while (line, 80, stdin);
	{
		sscanf_s(line, "%s %d %d %d", score.name, 40, &score.mid, &score.final, &score.quiz);
		score.number = ++cnt;
		fwrite(&score, sizeof(pscore), 1, f);
		fgets(line, 80, stdin);
	}
}

int printscore(FILE* f)
{
	rewind(f); //�� ������ �̵�
	pscore score;

	int readcnt = fread(&score, sizeof(pscore), 1, f);
	if (readcnt == 0)
	{
		printf("����� ���� ������ �ϳ��� �����ϴ�. >>\n");
		return 0;
	}

	printhead();
	while (!feof(f))
	{
		fprintf(stdout, "%6%18s%8d%8d%8d\n",
			score.number, score.name, score.mid, score.final, score.quiz);
		fread(&score, sizeof(pscore), 1, f);
	}
	fprintf(stdout, "%s\n", "   ------------------------------");

	return 1;
}

void printhead()
{
	printf("\n������ ���� ������ >>\n");
	fprintf(stdout, "%s\n", "   ------------------------------");
	fprintf(stdout, "8s%15s%10s%8s%8s", "��ȣ", "�̸�", "�߰�", "�⸻", "����");
	fprintf(stdout, "%s\n", "   ------------------------------");

}