#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fr = fopen("input.txt", "r");
	char** list[2];
	for (int i = 0; i < 2;i++)
	{
		char* string[20];
		fgets(string, 20, fr);
		list[i] = (char*) malloc(sizeof(char*) * 20);
		strcpy(list[i], string);
	}
	fclose(fr);

	FILE* fw = fopen("output.txt", "w");
	for (int i = 0; i < 2; i++)
	{
		fprintf(fw, "%s", list[i]);
	}
	fclose(fw);

}