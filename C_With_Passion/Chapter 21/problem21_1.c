#include <stdio.h>

int main(void)
{
	int ch = getchar();

	if (65 <= ch && ch <= 90)
		putchar(ch + 32);
	else if (97 <= ch && ch <= 122)
		putchar(ch - 32);
	else
		printf("Æ²·ÈÁö·Õ");

	return 0;
}