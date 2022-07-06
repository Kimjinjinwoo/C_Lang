#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "C and C++\t languages are best!";
	char* delimiter = " !\t";

	printf("문자열 \"%s\"을 >> \n", str);
	printf("구분자[%s]를 이용하여 토큰을 추출 >>\n", delimiter);
	char* ptoken = strtok(str, delimiter);

	while (ptoken)
	{
		printf("%s\n", ptoken);
		//NULL 넣는거 이해 잘 안되네;;;;
		ptoken = strtok(NULL, delimiter);
	}

	return 0;
}