#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE* fr = fopen("input.txt", "r");
	char arr[3][20];
	char (*ptr)[20] = arr;
	
	for (int ii = 0; ii < 3; ii++) {
		fgets(ptr[ii], 20, fr);
	}
	fclose(fr);

	

	FILE* fw = fopen("output.txt", "w");
	for (int ii = 0;ii < 3;ii++) {
		fputs( ptr[ii] , fw);
	}
	fclose(fw);
	
	return 0;
}