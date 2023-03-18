#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char line[100];
	FILE* fr = fopen(argv[1], "r");
	FILE* fw = fopen(argv[2], "w");

	while (feof(fr) == 0)
	{
		fgets(line, 100, fr);
		fputs(line, fw);
	}

	fclose(fr);
	fclose(fw);
}