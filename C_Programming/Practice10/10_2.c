#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	int nums[200] = { 0 };
	gets(str);

	for (int i = 0; i < strlen(str); i++)
	{
		int a = str[i];
		nums[a] += 1;
	}
	
	for (int i = 65; i <= 122; i++)
	{
		if (nums[i] > 0)
		{
			printf("%c:%d\n", i, nums[i]);
		}

	}

	return 0;
}