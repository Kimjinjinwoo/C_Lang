#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char d[20] = "C C++";
	char s[] = "Java";
	strcat(d, s);
	puts(d);
	puts("");

	char str[80];
	//asign �ȵǰ� strcpy�� ����!
	strcpy(str, "these ");
	strcat(str, "strings ");
	strcat(str, "are ");
	strcat(str, "concatenated.");
	puts(str);
	
	return 0;
}