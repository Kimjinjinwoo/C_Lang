#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int size_;
	scanf("%d ", &size_);
	char* pi = (char*)malloc(sizeof(char) * size_);
	gets(pi);
	int n = strlen(pi);
	for (int i = n-1; i >= 0; i--)
	{
		putchar(pi[i]);
	}
	free(pi);
	return 0;
}