#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	char fname[20];
	int ansList[40];
	scanf("%s", fname);

	FILE* f;
	if ((fopen_s(&f, fname, "r")) != 0)
	{
		puts("¿¡·¯");
		exit(1);
	}
	char str[10];
	int cnt = 0;

	fgets(str, 10, f);

	while (!feof(f))
	{
		int k = atoi(str);
		//puts(str);
		if (k >= 90)
		{
			cnt += 1;
			ansList[cnt] = k;
		}
		fgets(str, 10, f);
	}

	ansList[0] = cnt;

	for (int i = 0; i < cnt + 1; i++)
		printf("%d\n", ansList[i]);

	fclose(f);

	return 0;
}