#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch;

	//getchar, putchar
	/*
	while ((ch = getchar()) != 'q')
		putchar(ch);
	*/

	//_getche , _putch
	/*
	while ((ch = _getche()) != 'q')
		_putch(ch);
	*/

	// _getch , _putch
	while ((ch = _getch()) != 'q')
		_putch(ch);

	return 0;

}