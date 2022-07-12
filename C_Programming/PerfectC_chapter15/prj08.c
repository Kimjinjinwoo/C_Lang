#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* fname1 = "prj08.c";
	char* fname2 = "changedPrj08.c";
	rename(fname2, fname1);

	return 0;
}