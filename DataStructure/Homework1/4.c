#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[ ])
{
	char ch;
	char line[100];
	FILE* fr = fopen(argv[1], "r");
	FILE* fw = fopen("output.txt", "w");
	// loop 돌리면 되겠네
	while (feof(fr) == 0)
	{
		fgets(line, 100, fr);
		for (int i = 0; i < strlen(line); i++)
		{
			ch = line[i];
			//소문자 -> 대문자
			if (ch >= 'a' && ch <= 'z')
				ch -= 32;

			// 대문자 -> 소문자
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;

			fputc(ch, fw);
		}
		fputs("", fw);
	}
	fclose(fr);
	fclose(fw);
	return 0;
}
