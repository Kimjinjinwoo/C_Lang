#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* f;
	if (fopen_s(&f, "test.bin", "wb+") != 0)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	int out[] = { 10,20,30,40,50,60,70,80 };
	int size = sizeof(out) / sizeof(out[0]);
	printf("파일에 출력 자료: ");
	for (int i = 0; i < size; i++)
	{
		_putw(out[i], f);
		printf("%d ", out[i]);
	}
	printf("\n");

	rewind(f);

	for (int i = 0; i < size / 2; i++)
	{
		int in = _getw(f);
		fseek(f, sizeof(int), SEEK_CUR);
		printf("%d ", in);
	}
	printf("\n");
	fclose(f);

	return 0;
}