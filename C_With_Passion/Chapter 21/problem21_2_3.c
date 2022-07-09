#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char person1[1000], person2[1000];
	int len1, len2;
	gets(person1);
	gets(person2);

	len1 = strlen(person1);
	len2 = strlen(person2);
	
	char* deli = " ";

	char* ptoken1 = strtok(person1, deli);
	ptoken1 = strtok(NULL, deli);

	char* ptoken2 = strtok(person2, deli);
	ptoken2 = strtok(NULL, deli);

	int age1, age2;
	age1 = atoi(ptoken1);
	age2 = atoi(ptoken2);

	if (age1 > age2)
		puts("앞이 큼");
	else if (age1 < age2)
		puts("뒤가 큼");
	else
		puts("같음");

	return 0;

}