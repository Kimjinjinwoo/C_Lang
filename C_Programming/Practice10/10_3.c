#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	//문제 잘못 이해했음....
	for (int i = 0 ; i< 1 ; i++)
	{
		char str1[200], str2[200];

		gets(str1);
		int len1 = strlen(str1);
		if (len1 < 5 || len1 > 10)
		{
			printf("Retry\n");
			continue;
		}
		gets(str2);
		int len2 = strlen(str2);
		if (len2 < 5 || len2 > 10)
		{
			printf("Retry\n");
			continue;
		}


		int t = strcmp(str1, str2);

		

		if (t == 0)
		{
			printf("Done");
			break;
		}
		else
		{
			printf("Retry\n");
		}
	}
}