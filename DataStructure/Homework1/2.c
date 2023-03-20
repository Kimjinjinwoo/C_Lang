#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Student {
	int idx;
	char name[10];
	double score1;
	double score2;
}student;

int main(void)
{
	int idx, cnt = 0;
	double score1, score2;
	
	FILE* fr = fopen("input.txt", "r");
	student* List = (student*)malloc(sizeof(student));
	while (feof(fr) == 0)
	{
		char name[10];
		
		List = realloc(List, sizeof(student) * (cnt + 1) );

		fscanf(fr, "%d %s %lf %lf", &idx, &name, &score1, &score2);
		
		List[cnt].idx = idx;
		strcpy(List[cnt].name, name);
		List[cnt].score1 = score1;
		List[cnt].score2 = score2;

		cnt++;
	}
	fclose(fr);
	FILE* fw = fopen("output.txt", "w");
	for (int i = 0; i < cnt; i++)
	{
		fprintf(fw, "%d %s %g %g %g\n", List[i].idx, List[i].name, List[i].score1, List[i].score2, (List[i].score1 + List[i].score2));
	}
	free(List);
	fclose(fw);
	return 0;
}