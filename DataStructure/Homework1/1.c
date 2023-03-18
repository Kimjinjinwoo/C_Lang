#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int idx;
	double score1, score2;
	char name[20];
	FILE* fr = fopen("input.txt", "r");
	FILE* fw = fopen("output.txt", "w");

	while (feof(fr) == 0)
	{
		fscanf(fr, "%d %s %lf %lf", &idx, name, &score1, &score2);
		fprintf(fw, "%d %s %g %g %g\n", idx, name, score1, score2, (score1 + score2));
	}
	fclose(fr);
	fclose(fw);
	return 0;
}