#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char* java = "java";
	printf("%s ", java);

	//�̰� �ȵ�
	java[1] = 'A';
	printf("%c", java[1]);
}