#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char d[20] = "C C++";
	char s[] = "Java";
	strcpy(d, s);
	puts(d);
	puts(s);

	return 0;
}