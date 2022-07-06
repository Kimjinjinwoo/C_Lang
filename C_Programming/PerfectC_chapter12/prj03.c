#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char c[] = "C C++ JAVA";
	c[5] = '\0';
	printf("%s\n%s\n", c, (c + 6));
}