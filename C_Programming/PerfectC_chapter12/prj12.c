#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "C and C++\t languages are best!";
	char* delimiter = " !\t";

	printf("���ڿ� \"%s\"�� >> \n", str);
	printf("������[%s]�� �̿��Ͽ� ��ū�� ���� >>\n", delimiter);
	char* ptoken = strtok(str, delimiter);

	while (ptoken)
	{
		printf("%s\n", ptoken);
		//NULL �ִ°� ���� �� �ȵǳ�;;;;
		ptoken = strtok(NULL, delimiter);
	}

	return 0;
}