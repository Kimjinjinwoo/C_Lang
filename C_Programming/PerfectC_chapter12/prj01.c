#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//문자열입력, 문자입력
	char my[400];
	char me;

	scanf("%s ", my);
	scanf("%c", &me);
	
	printf("%s\n", my);
	printf("%c\n", me);

	/*
	char java[] = { 'J' , 'A' , 'V' , 'A' , '\0' };
	printf("%s\n", java);

	char py[] = "Python";
	printf("%s\n", py);

	char csharp[5] = "C#";
	printf("%s\n", csharp);

	printf("%c %c\n", csharp[0], csharp[1]);
	*/

	return 0;
}