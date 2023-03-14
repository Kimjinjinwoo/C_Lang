#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp = fopen("input.txt", "r");
	int n;
	int sum = 0;
	fscanf(fp, "%d",&n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		fscanf(fp, "%d", &tmp);
		sum += tmp;
	}
	fclose(fp);
	//printf("%d", sum);
	
	FILE* fw = fopen("output.txt", "w");
	fprintf(fw, "%d", sum);
}
