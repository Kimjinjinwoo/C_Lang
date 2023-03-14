#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp = fopen("input.txt", "r");
	
	int n;
	fscanf(fp, "%d", &n);
	fclose(fp);
	//printf("%d\n", n);
	
	int result = n * (n + 1) / 2;
	//printf("%d", result);
	FILE* fp2 = NULL;
	fp2 = fopen("output.txt", "w");
	fprintf(fp2, "%d", result);
	fclose(fp2);

	return;
}