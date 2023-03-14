#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fr = fopen("input.txt", "r");
	int n;
	fscanf(fr, "%d", &n);
	float*list = (float*) malloc(n * sizeof(float));
	for (int i = 0; i < n; i++)
	{
		fscanf(fr, "%f", &list[i]);
	}
	fclose(fr);

	FILE* fw = fopen("output.txt", "w");

	for (int i = 0; i < n; i++)
	{
		if ((float) (int) list[i] != list[i])
		{
			fprintf(fw, "%g ", list[i]);
		}
	}
	fclose(fw);
	return 0;
}