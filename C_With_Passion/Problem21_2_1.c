#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char str[20];
	scanf("%s", str);

	int i = 0;
	int sum = 0;
	while (str[i]!= '\0')
	{
		if (48 < str[i] && str[i] < 58)
		{
			sum += str[i]-48 ;
		}
		i++;
	}
	printf("%d", sum);
	return 0;
}