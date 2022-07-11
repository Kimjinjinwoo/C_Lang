#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	char fname[20];
	int ansList[40];
	scanf("%s", fname);

	FILE* f;
	if ((fopen_s(&f, fname, "rb")) != 0)
	{
		puts("¿¡·¯");
		exit(1);
	}
	char str[3];
	int cnt = 0;

	fread(str, sizeof("90") , 1, f);
	//printf("%d", sizeof("90"));
	//printf("    %d\n", sizeof("\n"));
	
	while (!feof(f))
	{
		str[2] = '\0';
		puts(str);
		//printf("%s\n", str);
		int k = atoi(str);
		
		if (k >= 90)
		{
			//printf("%d\n", k);
			cnt += 1;
			ansList[cnt] = k;
		}
		fread(str, 1, 1, f);
		fread(str, sizeof("90"), 1, f);
	}

	ansList[0] = cnt;

	for (int i = 0; i < cnt + 1; i++)
		printf("%d\n", ansList[i]);

	return 0;
}